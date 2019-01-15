#pragma once

#include <stdio.h>
#include <windows.h>
#include "data_structures.h"

void getGameInput(int *c_v, int *c_h);
void animate(int c_v, int c_h, FieldProperties (*cards)[FIELD_SIZE]);
void printField(FieldProperties (*cards)[FIELD_SIZE]);
void printPart(int line, int state, int image);

void getGameInput(int *c_v, int *c_h) {
	scanf("%d %d", c_v, c_h);
}

void animate(int c_v, int c_h, FieldProperties (*cards)[FIELD_SIZE]) {
	int d;
	int state = cards[c_v][c_h].animationState;
	if (state == 0)
	{
		d = 1;
	} else {
		d = -1;
	}
	for (; state <= 6 && state >= 0; state += d)
	{
		cards[c_v][c_h].animationState = state;
		printField(cards);
	}
}

void printField(FieldProperties (*cards)[FIELD_SIZE]) {
	system("cls");
	for (int c_v = 0; c_v < FIELD_SIZE; ++c_v) // cards vertical
	{
		for (int line = 0; line < 4; ++line) // lines height of a card
		{
			for (int c_h = 0; c_h < FIELD_SIZE; ++c_h) // cards horizontally
			{
				printPart(line, cards[c_v][c_h].animationState, cards[c_v][c_h].image);
			}
			printf("\n");
		}
		printf("\n");
	}
}

void printPart(int line, int state, int image) {
	switch (line) {
		case 0: // top line
			switch (state) {
				case -1:
					printf("         ");
					break;
				case 0:
					printf("  _____  ");
					break;
				case 1:
					printf("   ___   ");
					break;
				case 2:
					printf("    _    ");
					break;
				case 3:
					printf("         ");
					break;
				case 4:
					printf("    _    ");
					break;
				case 5:
					printf("   ___   ");
					break;
				case 6:
					printf("  _____  ");
					break;
			}
			break;
		case 1: // upper mid
			switch (state) {
				case -1:
					printf("         ");
					break;
				case 0:
					printf(" |     | ");
					break;
				case 1:
					printf("  |   |  ");
					break;
				case 2:
					printf("   | |   ");
					break;
				case 3:
					printf("    |    ");
					break;
				case 4:
					printf("   | |   ");
					break;
				case 5:
					printf("  |   |  ");
					break;
				case 6:
					printf(" |     | ");
					break;
			}
			break;
		case 2: //lower mid
			switch (state) {
				case -1:
					printf("         ");
					break;
				case 0:
					printf(" |  ?  | ");
					break;
				case 1:
					printf("  | ? |  ");
					break;
				case 2:
					printf("   | |   ");
					break;
				case 3:
					printf("    |    ");
					break;
				case 4:
					printf("   | |   ");
					break;
				case 5:
					printf("  | %c |  ", image);
					break;
				case 6:
					printf(" |  %c  | ", image);
					break;
			}
			break;
		case 3: // bottom line
			switch (state) {
				case -1:
					printf("         ");
					break;
				case 0:
					printf(" |_____| ");
					break;
				case 1:
					printf("  |___|  ");
					break;
				case 2:
					printf("   |_|   ");
					break;
				case 3:
					printf("    |    ");
					break;
				case 4:
					printf("   |_|   ");
					break;
				case 5:
					printf("  |___|  ");
					break;
				case 6:
					printf(" |_____| ");
					break;
			}
			break;
	}
}