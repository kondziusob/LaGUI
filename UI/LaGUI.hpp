#ifndef lagui_gui
#define lagui_gui

#define LCDWIDTH	240 //has to agree with the driver
#define LCDHEIGHT	320 //has to agree with the driver

#include "Parent.hpp"

extern "C" {
	void os_init(void);
}

class LaGUI {
	public:
		void setup();
		Parent* scene;
		void setScene(Parent* scene);
		void draw();
		void main_loop();
		int  add_task(int (*f)(int), unsigned long l, int i);
		void clear_screen();
		void display_string_xy(char *str, uint16_t x, uint16_t y);
		void select(Node* node);
};

#endif