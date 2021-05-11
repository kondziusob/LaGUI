#ifndef lagui_parent
#define lagui_parent

#include <stdint.h>
#include "Node.hpp"

class Parent : public Node {
	public:
		Node* children[16];
		int8_t ptr = 0;
		virtual void draw() = 0;
		void addChild(Node* child);
		void removeChild();
		using Node::Node;
};

#endif