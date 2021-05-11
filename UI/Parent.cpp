#include "Parent.hpp"
#include <cstddef>

void Parent::addChild(Node* child) {
	(*this).children[ptr] = child;
	(*this).ptr++;
	(*child).setParent(this);
}

void Parent::removeChild() {
	(*this).children[(*this).ptr--] = NULL;
}
