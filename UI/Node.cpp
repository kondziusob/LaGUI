#include "Node.hpp"

Node::Node(uint16_t posX, uint16_t posY, uint16_t width, uint16_t height) {
	(*this).posX = posX;
	(*this).posY = posY;
	(*this).width = width;
	(*this).height = height;
}

void Node::setParent(Node* parent) {
	(*this).parent = parent;
}

void Node::on(EType event, void (*cb)(Node*)) {
	switch (event) {
		case ROT_INC: (*this).on_rot_inc = cb; break;
		case ROT_DEC: (*this).on_rot_dec = cb; break;
		case NORTH: (*this).on_north = cb; break;
		case NORTH_RPT: (*this).on_north_rpt = cb; break;
		case NORTH_LONG: (*this).on_north_long = cb; break;
		case SOUTH: (*this).on_south = cb; break;
		case SOUTH_RPT: (*this).on_south_rpt = cb; break;
		case SOUTH_LONG: (*this).on_south_long = cb; break;
		case EAST: (*this).on_east = cb; break;
		case EAST_RPT: (*this).on_east_rpt = cb; break;
		case EAST_LONG: (*this).on_east_long = cb; break;
		case WEST: (*this).on_west = cb; break;
		case WEST_RPT: (*this).on_west_rpt = cb; break;
		case WEST_LONG: (*this).on_west_long = cb; break;
		case CENTER: (*this).on_center = cb; break;
		case CENTER_RPT: (*this).on_center_rpt = cb; break;
		case CENTER_LONG: (*this).on_center_long = cb; break;
	}
}

void Node::trigger(EType event) {
	switch (event) {
		case ROT_INC: 
			if ((*this).on_rot_inc != NULL) {
				(*this).on_rot_inc(this); 
			}
			break;
		case ROT_DEC: 
			if ((*this).on_rot_dec != NULL) {
				(*this).on_rot_dec(this); 
			}
			break;
		case NORTH: 
			if ((*this).on_north != NULL) {
				(*this).on_north(this);
			}
			break;
		case NORTH_RPT: 
			if ((*this).on_north_rpt != NULL) {
				(*this).on_north_rpt(this);	
			}
			break;
		case NORTH_LONG: 
			if ((*this).on_north_long != NULL) {
				(*this).on_north_long(this);
			}
			break;
		case SOUTH: 
			if ((*this).on_south != NULL) {
				(*this).on_south(this);
			}
			break;
		case SOUTH_RPT: 
			if ((*this).on_south_rpt != NULL) {
				(*this).on_south_rpt(this);
			}
			break;
		case SOUTH_LONG: 
			if ((*this).on_south_long != NULL) {
				(*this).on_south_long(this);
			}
			break;
		case EAST: 
			if ((*this).on_east != NULL) {
				(*this).on_east(this);
			}
			break;
		case EAST_RPT: 
			if ((*this).on_east_rpt != NULL){
				(*this).on_east_rpt(this);
			}
			break;
		case EAST_LONG:
			if ((*this).on_east_long != NULL) {
				(*this).on_east_long(this);
			}
			break;
		case WEST: 
			if ((*this).on_west != NULL) {
				(*this).on_west(this);
			}
			break;
		case WEST_RPT: 
			if ((*this).on_west_rpt != NULL) {
				(*this).on_west_rpt(this);
			}
			break;
		case WEST_LONG: 
			if ((*this).on_west_long != NULL) {
				(*this).on_west_long(this);
			}
		 	break;
		case CENTER: 
			if ((*this).on_center != NULL) {
				(*this).on_center(this);
			}
			break;
		case CENTER_RPT: 
			if ((*this).on_center_rpt != NULL) {
				(*this).on_center_rpt(this);
			}
			break;
		case CENTER_LONG: 
			if ((*this).on_center_long != NULL) {
				(*this).on_center_long(this);
			}
			break;
	}
}