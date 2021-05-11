#ifndef lagui_list
#define lagui_list

#include "Box.hpp"
#include <cstddef>

class ListItem;

class List : public Box {
	private:
		uint8_t offset = 0;
		uint8_t selected = 0;
	public: 
		List(uint16_t posX, uint16_t posY, uint16_t width, uint16_t height);
		void addChild(ListItem* item);
		void draw();
		void select(uint8_t index);
		void select_next();
		void select_prev();
		ListItem* getSelected();
};

class ListItem : public Box {
	private:
		char* text; 
	public:
		ListItem(uint16_t posX, uint16_t posY, uint16_t width, char* text);
		char* getText();
		void draw();
		void drawSelectionLine(uint16_t color);
};

#endif