#pragma once

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "data_structures.h"

void allocBuffer();
void freeBuffer();
void buffer(int startIndex, int length, char *string);
void getGameInput(int *c_v, int *c_h);
void animate(int c_v, int c_h, FieldProperties (*cards)[FIELD_SIZE], int *points, int player);
void printField(FieldProperties (*cards)[FIELD_SIZE], int *points, int player);
void printPart(int line, int state, int image, int startIndex);
int gameOver(int *points);
