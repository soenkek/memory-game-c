#pragma once

#define FIELD_SIZE  4

typedef struct {
	int image;
	int animationState; // [0...6]
	int visibility; // 1 = visible; 0 = invisible
} FieldProperties;