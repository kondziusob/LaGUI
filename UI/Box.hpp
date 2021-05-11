#ifndef lagui_box 
#define lagui_box

#include "Parent.hpp"

class Box : public Parent {
	public:
		virtual void draw();
		using Parent::Parent;
};

#endif