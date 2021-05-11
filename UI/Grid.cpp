#include "Grid.hpp"
#include "Extern.hpp"

Grid::Grid(uint16_t rows, uint16_t columns, uint16_t posX, uint16_t posY, uint16_t width, uint16_t height) : Box(posX, posY, width, height) {
	(*this).rows = rows;
	(*this).columns = columns;
}

void Grid::addChild(Node* child, uint16_t row, uint16_t column, uint16_t rowspan, uint16_t columnspan) {
	(*this).children[ptr] = child;
	(*child).setParent(this);

	(*child).style.position = ABSOLUTE;
	(*child).posY = ((*this).height / (*this).rows) * row;
	(*child).height = ((*this).height / (*this).rows) * rowspan;
	(*child).posY = ((*this).width / (*this).columns) * column;
	(*child).posX = ((*this).width / (*this).columns) * columnspan;

	ptr++;
}

void Grid::draw() {
	Box::draw();
}