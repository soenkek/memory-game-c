#pragma once

#define FIELD_SIZE 4
#define CARD_SIZE_HORIZONTAL 11
#define CARD_SIZE_VERTICAL 5

typedef enum {
	INVISIBLE = -1, //card invisible
	HIDDEN = 0, //image hidden...
	TURN_1 = 1,
	TURN_2 = 2,
	TURN_3 = 3,
	TURN_4 = 4,
	TURN_5 = 5,
	TURN_6 = 6,
	TURN_7 = 7,
	SHOWN = 8
} AnimationStates;

typedef enum {
	TOP_LEFT = 218,
	TOP_RIGHT = 191,
	BOTTOM_LEFT = 192,
	BOTTOM_RIGHT = 217,
	HORIZONTAL = 196,
	VERTICAL = 179
} BoxDrawingCharacters;

typedef struct {
	int image;
	AnimationStates animationState; // [0...6], -1 = invisible
} FieldProperties;


//	printf("%c%c%c\n%c %c\n%c%c%c", 218, 196, 191, 179, 179, 192, 196, 217);
//	return 0;