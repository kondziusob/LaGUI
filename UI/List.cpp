#include "List.hpp"
#include "EType.hpp"
#include "Extern.hpp"

void sn(Node* node) {
	List* list = (List*) node;
	(*list).select_next();
}

void sp(Node* node) {
	List* list = (List*) node;
	(*list).select_prev();
}

void cn(Node* node) {
	List* list = (List*) node;
	(*list).getSelected()->trigger(CENTER);
}

List::List(uint16_t posX, uint16_t posY, uint16_t width, uint16_t height) : Box(posX, posY, width, height) {
	(*this).on(ROT_INC, &sn);
	(*this).on(ROT_DEC, &sp);
	(*this).on(SOUTH, &sn);
	(*this).on(NORTH, &sp);
	(*this).on(EAST, &cn);
	(*this).on(CENTER, &cn);
}

void List::addChild(ListItem* item) {
	(*this).children[ptr] = item;
	(*item).setParent(this);

	(*item).posX = 0;
	(*item).posY = (*this).ptr * 16;

	(*item).width = (*this).width - 4;

	(*this).ptr++;
}

void List::draw() {
	Box::draw();

	uint8_t maxNum = (*this).height / 16;

	for (uint8_t i = (*this).offset; i < maxNum && i < (*this).ptr; i++) {
		(*this).children[i]->posY = (i - (*this).offset) * 16;
		(*this).children[i]->draw();
	}

	(*this).select((*this).selected);
}

void List::select(uint8_t index) {
	((ListItem*) (*this).children[(*this).selected])->drawSelectionLine((*this).style.background);
	(*this).selected = index;
	((ListItem*) (*this).children[(*this).selected])->drawSelectionLine((*this).children[(*this).selected]->style.border.color);
}

void List::select_next() {
	int index = (*this).selected + 1;
	
	if (index >= (*this).ptr) {
		index = 0;
	}

	(*this).select(index);
}

void List::select_prev() {
	int index = (*this).selected - 1;
	
	if (index < 0) {
		index = (*this).ptr - 1;
	}

	(*this).select(index);	
}

ListItem* List::getSelected() {
	return (*this).children[(*this).selected];
}

ListItem::ListItem(uint16_t posX, uint16_t posY, uint16_t width, char* text) : Box(posX, posY, width, 16) {
	(*this).text = text;
}

void ListItem::draw() {
	Box::draw();

	display_string_xy((*this).text, (*this).posX + 6, (*this).posY + 6);
}

void ListItem::drawSelectionLine(uint16_t color) {
	fill_rectangle((rectangle){(*this).posX + (*this).width - 14, (*this).posX + (*this).width - 6, 
					(*this).posY + 6, (*this).posY + 14}, 
				   	color);
} 

char* ListItem::getText() {
	return (*this).text;
}