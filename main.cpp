#include "UI/LaGUI.hpp"
#include "UI/EType.hpp"
#include "UI/Box.hpp"
#include "UI/List.hpp"

//#include "UI/Extern.hpp"

extern "C" void __cxa_pure_virtual() { while (1); }

extern "C" {
	#include <stdio.h>
	#include "ruota.h"
	#include <avr/io.h>
	#include <avr/interrupt.h>
	#include <string.h>
	#include <lcd.h>
	#include "audio.h"
}

#include "ff.h"

LaGUI g;

void play(Node* node) {
	ListItem* item = (ListItem*) node;

	FIL File;
	if (f_open(&File, (*item).getText(), FA_READ) == FR_OK) {
		audio_load(&File);	
	} else {
		display_string("Cannot open file");
	}
}

int main() {
	g.setup();

	List box((uint16_t) 0, (uint16_t) 0, (uint16_t) LCDHEIGHT, (uint16_t) LCDWIDTH);
	box.style.background = (uint16_t) 0x0000;
	box.style.border.color = (uint16_t) 0x447D;

	ListItem* items[14];
	
	FATFS fs;
    FRESULT fs_res;
    fs_res = f_mount(&fs, "", 1);

    if (fs_res == FR_OK) {
    	FRESULT res;
    	DIR dir;
    	UINT i = 0;
    	static FILINFO fno;
    	char fname[14][13];

    	res = f_opendir(&dir, "/");
    	if (res == FR_OK) {
    		for (;;) {
    			res = f_readdir(&dir, &fno);
    			if (res != FR_OK || fno.fname[0] == 0 || i == 13) break;
    			if (!(fno.fattrib & AM_DIR)) {
    				strcpy(fname[i], fno.fname);

    				items[i] = new ListItem ((uint16_t) 0, (uint16_t) 0, (uint16_t) LCDHEIGHT, fname[i]);
    				(*items[i]).style.border.color = (uint16_t) 0xFC04;
    				(*items[i]).on(CENTER, &play);

    				box.addChild(items[i]);
    				i++;
    			}
    		}

    		items[13] = new ListItem ((uint16_t) 0, (uint16_t) 0, (uint16_t) LCDHEIGHT, "#> ");
    		box.addChild(items[13]);

    		g.setScene(&box);

    		g.draw();

    		box.select(0);

    		g.main_loop();
    	}
    }


	return 0;
}
