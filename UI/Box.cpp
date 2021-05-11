#include "Box.hpp"
#include "Extern.hpp"

#include <cstddef>

void Box::draw() {
	uint16_t offsetX = 0;
	uint16_t offsetY = 0;
	if ((*this).style.position != FIXED && (*this).parent != NULL) {
		offsetX = (*this).parent->posX + (*this).style.border.thickness;
		offsetY = (*this).parent->posY + (*this).style.border.thickness;
	}

	if ((*this).style.position == RELATIVE) {
		offsetX += (*this).style.left;
		offsetY += (*this).style.top;
	}

	if ((*this).parent == NULL) {
		clear_screen();
	}

	fill_rectangle((rectangle){offsetX + (*this).posX, offsetX + (*this).posX + (*this).width, offsetY + (*this).posY, offsetY + (*this).posY + (*this).height}, 
				   (*this).style.border.color);
	fill_rectangle((rectangle){offsetX + (*this).posX + (*this).style.border.thickness, 
					offsetX + (*this).posX + (*this).width - (*this).style.border.thickness, 
					offsetY + (*this).posY + (*this).style.border.thickness, 
					offsetY + (*this).posY + (*this).height - (*this).style.border.thickness}, (*this).style.background);

	for (int8_t i = 0; i < (*this).ptr; i++) {
		if ((*this).children[i] != NULL) {
			(*this).children[i]->draw();
		}
	}
}