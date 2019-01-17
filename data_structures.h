#pragma once

#define FIELD_SIZE  4

typedef enum {
	INVISIBLE = -1, //card invisible
	HIDDEN = 0, //image hidden...
	TURN_1 = 1,
	TURN_2 = 2,
	TURN_3 = 3,
	TURN_4 = 4,
	TURN_5 = 5,
	SHOWN = 6
} AnimationStates;

typedef struct {
	int image;
	AnimationStates animationState; // [0...6], -1 = invisible
} FieldProperties;