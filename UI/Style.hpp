#ifndef lagui_style
#define lagui_style

#define WHITE       0xFFFF
#define BLACK       0x0000
#define BLUE        0x001F      
#define GREEN       0x07E0      
#define CYAN        0x07FF      
#define RED         0xF800      
#define MAGENTA     0xF81F      
#define YELLOW      0xFFE0      

enum POSITION {RELATIVE, ABSOLUTE, FIXED};

struct LINE {
	LINE() : thickness((uint8_t) 2), color(WHITE) {};
	uint8_t thickness;
	uint16_t color;
};

struct STYLE {
	STYLE() : border(LINE()), foreground(WHITE), background(BLACK), position(RELATIVE), left((uint8_t) 0), top((uint8_t) 0) {};
	LINE border;
	uint16_t foreground;
	uint16_t background;
	POSITION position;
	uint16_t left;
	uint16_t top;
};

#endif