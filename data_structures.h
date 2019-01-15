#pragma once

#define FIELD_SIZE  4

typedef struct {
	int image;
	int animationState; // [0...6], -1 = invisible
} FieldProperties;