# LaGUI
## _Simple AVR GUI library optimised for LaFortuna boards_

Latest version always on [GitHub](https://github.com/kondziusob/LaGUI)

## Features
- OOP programming interface
- Parts of C++ STL ported from [ArduinoSTL](https://github.com/mike-matera/ArduinoSTL)
- Tree structure of UI elements simmilar 
- Uses KPZ's LCD and encoder drivers, RIOS and FatFS to provide decent reliability 
- Built in input handling (the currently selected Node receives events)
- Different style aspects (border, color etc)

## TODO
- Add more Node classes 
- Automate redrawing of the UI when necessary, making it an OS task
- Extend the C++ interface so that it is not necessary to use the builtin C functions
- Create a demo 

## Usage
```cpp
LaGUI g; //create a new LaGUI instance

void handler(Node n) {
    g.clear_screen();
    g.display_string_xy(0, 0, "Clicked");
}

int main() {
    g.setup(); //initialise the OS and the event handler task

    Box scene((uint16_t) 0, (uint16_t) 0, (uint16_t) LCDHEIGHT, (uint16_t) LCDWIDTH); //make a new Box
    scene.style.border.thickness = 4; //set some styling
    scene.style.border.color = 0x40FE;

    //the "new" keyword comes with the STL
    Box* child = new Box((uint16_t) 40, (uint16_t) 123, (uint16_t) 50, (uint16_t) 50);
    (*child).style.position = RELATIVE; //position will be relative to the box inserted normally 
    scene.addChild(child);

    List* list = new List((uint16_t) 90, (uint16_t) 0, (uint16_t) LCDHEIGHT - 90, (uint16_t) LCDWIDTH);
    ListItem* item = new ListItem((uint16_t) 40, (uint16_t) 123, (uint16_t) 50, "test item 2");
    (*item).on(CENTER, &handler);
    (*list).addChild(new ListItem((uint16_t) 40, (uint16_t) 123, (uint16_t) 50, "test item 1"));
    (*list).addChild(item);
    scene.addChild(list);

    g.setSelected(list); //list will receive events
    g.draw();
    g.main_loop(); //enable interrupts and start the main loop
    
    return 0;
}
```
## The demo
This demo is a very basic music player. It supports up to 13 WAV files placed in the root directory of SD card.
Once a file is selected, the program will attempt to play it using the builtin headphone output.

### TODO
- Add multi-page function
- Add play/pause
- Make the UI less bare-bones

(C) Konrad Sobczak (kks1g19@soton.ac.uk) 2021
This code also uses the LaFortuna-WAV-lib by [fatcookies](https://github.com/fatcookies)


