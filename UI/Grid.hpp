#ifndef lagui_grid
#define lagui_grid

#include "Box.hpp"

class Grid : public Box {
	private:
		uint16_t rows;
		uint16_t columns;
	public:
		Grid(uint16_t rows, uint16_t columns, uint16_t posX, uint16_t posY, uint16_t width, uint16_t height);
		void draw();
		void addChild(Node* child, uint16_t row, uint16_t column, uint16_t rowspan, uint16_t columnspan);
};

#endif