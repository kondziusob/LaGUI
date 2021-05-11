#include "LaGUI.hpp"

extern "C" {
	#include "os.h"
}

extern "C" {
	void loop() {
		sei();
		for(;;){}
		cli();
	}
}

int event_loop(int state);

volatile Node* selection = NULL;

void LaGUI::setup() {
	os_init();

	(*this).add_task(event_loop, 250, 1);
}

void LaGUI::setScene(Parent* scene) {
	(*this).scene = scene;
	(*this).scene->setParent(NULL);
	selection = scene;
}

void LaGUI::draw() {
	(*this).scene->draw();
}

void LaGUI::main_loop() {
	loop();
}

int LaGUI::add_task(int (*f)(int), unsigned long l, int i) {
	return os_add_task(f, l, i);
}

void LaGUI::display_string_xy(char *str, uint16_t x, uint16_t y) {
	display_string_xy(str, x, y);
}

void LaGUI::clear_screen() {
	clear_screen();
}

void LaGUI::select(Node* node) {
	selection = node;
}

int event_loop(int state) {
	if (selection == NULL) {
		return state;
	}

	int delta = os_enc_delta();
	
	if (delta > 0) {
		(*selection).trigger(ROT_INC);
	}

	if (delta < 0) {
		(*selection).trigger(ROT_DEC);
	}

	if (get_switch_short(_BV(SWN))) {
		(*selection).trigger(NORTH);
	}

	if (get_switch_rpt(_BV(SWN))) {
		(*selection).trigger(NORTH_RPT);
	}

	if (get_switch_long(_BV(SWN))) {
		(*selection).trigger(NORTH_LONG);
	}

	if (get_switch_short(_BV(SWS))) {
		(*selection).trigger(SOUTH);
	}

	if (get_switch_rpt(_BV(SWS))) {
		(*selection).trigger(SOUTH_RPT);
	}

	if (get_switch_long(_BV(SWS))) {
		(*selection).trigger(SOUTH_LONG);
	}

	if (get_switch_short(_BV(SWE))) {
		(*selection).trigger(EAST);
	}

	if (get_switch_rpt(_BV(SWE))) {
		(*selection).trigger(EAST_RPT);
	}

	if (get_switch_long(_BV(SWE))) {
		(*selection).trigger(EAST_LONG);
	}

	if (get_switch_short(_BV(SWW))) {
		(*selection).trigger(WEST);
	}

	if (get_switch_rpt(_BV(SWW))) {
		(*selection).trigger(WEST_RPT);
	}

	if (get_switch_long(_BV(SWW))) {
		(*selection).trigger(WEST_LONG);
	}

	if (get_switch_short(_BV(SWC))) {
		(*selection).trigger(CENTER);
	}

	if (get_switch_rpt(_BV(SWC))) {
		(*selection).trigger(CENTER_RPT);
	}

	if (get_switch_long(_BV(SWC))) {
		(*selection).trigger(CENTER_LONG);
	}

	return state;
}