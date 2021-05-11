#ifndef lagui_node
#define lagui_node

#include <stdint.h>
#include <cstddef>

#include "Style.hpp"
#include "EType.hpp"

class Node;

class Node {
	private:
		void (*on_rot_inc)(Node*) = NULL;
		void (*on_rot_dec)(Node*) = NULL;
		void (*on_north)(Node*) = NULL;
		void (*on_north_rpt)(Node*) = NULL;
		void (*on_north_long)(Node*) = NULL;
		void (*on_south)(Node*) = NULL;
		void (*on_south_rpt)(Node*) = NULL;
		void (*on_south_long)(Node*) = NULL;
		void (*on_east)(Node*) = NULL;
		void (*on_east_rpt)(Node*) = NULL;
		void (*on_east_long)(Node*) = NULL;
		void (*on_west)(Node*) = NULL;
		void (*on_west_rpt)(Node*) = NULL;
		void (*on_west_long)(Node*) = NULL;
		void (*on_center)(Node*) = NULL;
		void (*on_center_rpt)(Node*) = NULL;
		void (*on_center_long)(Node*) = NULL;
	public:
		uint16_t width;
		uint16_t height;
		uint16_t posX;
		uint16_t posY;

		
		STYLE style;
		Node* parent;
		Node(uint16_t posX, uint16_t posY, uint16_t width, uint16_t height);
		virtual void draw() = 0;
		void setParent(Node* parent);

		void select();
		void unselect();

		void trigger(EType event);
		void on(EType event, void (*cb)(Node*));
};

#endif