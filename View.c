#include "View.h"

void getGameInput(int *c_v, int *c_h) {
	scanf("%d %d", c_v, c_h);
	(*c_v)--;
	(*c_h)--;
}

int gameOver(int *points) {
	system("cls");
	int player;
	if (points[0] > points[1])
		player = 1;
	else
		player = 2;
	printf("\n\t%d-%d\nSpieler%d gewinnt!\n\nErneut spielen? J/N\n", points[0], points[1], player);
	char c;
	scanf(" %c", &c);
	if (c == 74 || c == 106) {
		return 1;
	}
	else {
		return 0;
	}
}

void animate(int c_v, int c_h, FieldProperties (*cards)[FIELD_SIZE], int *points, int player) {
	int d;
	int state = cards[c_v][c_h].animationState;
	if (state == 0)
	{
		d = 1;
	} else {
		d = -1;
	}
	for (; state <= SHOWN && state >= HIDDEN; state += d)
	{
		cards[c_v][c_h].animationState = state;
		printField(cards, points, player);
	}
}

void printField(FieldProperties (*cards)[FIELD_SIZE], int *points, int player) {
	system("cls");
	for (int c_v = 0; c_v < FIELD_SIZE; ++c_v) // cards vertical
	{
		for (int line = 0; line < 5; ++line) // lines height of a card
		{
			for (int c_h = 0; c_h < FIELD_SIZE; ++c_h) // cards horizontally
			{
				printPart(line, cards[c_v][c_h].animationState, cards[c_v][c_h].image);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\nSpieler1: %d\nSpieler2: %d\n\nSpieler%d ist am Zug!\n", points[0], points[1], player + 1);
}

void printPart(int line, int state, int image) {
	switch (line) {
		case 0: // top line
			switch (state) {
				case INVISIBLE:
				case TURN_4:
					printf("           ");
					break;
				case HIDDEN:
				case SHOWN:
					printf(" %c%c%c%c%c%c%c%c%c ", TOP_LEFT, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, TOP_RIGHT);
					break;
				case TURN_1:
				case TURN_7:
					printf("  %c%c%c%c%c%c%c  ", TOP_LEFT, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, TOP_RIGHT);
					break;
				case TURN_2:
				case TURN_6:
					printf("   %c%c%c%c%c   ", TOP_LEFT, HORIZONTAL, HORIZONTAL, HORIZONTAL, TOP_RIGHT);
					break;
				case TURN_3:
				case TURN_5:
					printf("    %c%c%c    ", TOP_LEFT, HORIZONTAL, TOP_RIGHT);
					break;
			}
			break;
		case 1: // upper mid
		case 3: //lower mid
			switch (state) {
				case INVISIBLE:
					printf("           ");
					break;
				case HIDDEN:
				case SHOWN:
					printf(" %c       %c ", VERTICAL, VERTICAL);
					break;
				case TURN_1:
				case TURN_7:
					printf("  %c     %c  ", VERTICAL, VERTICAL);
					break;
				case TURN_2:
				case TURN_6:
					printf("   %c   %c   ", VERTICAL, VERTICAL);
					break;
				case TURN_3:
				case TURN_5:
					printf("    %c %c    ", VERTICAL, VERTICAL);
					break;
				case TURN_4:
					printf("     %c     ", VERTICAL);
					break;
			}
			break;
		case 2: // mid
			switch (state) {
				case INVISIBLE:
					printf("           ");
					break;
				case HIDDEN:
					printf(" %c   ?   %c ", VERTICAL, VERTICAL);
					break;
				case TURN_1:
					printf("  %c  ?  %c  ", VERTICAL, VERTICAL);
					break;
				case TURN_2:
					printf("   %c ? %c   ", VERTICAL, VERTICAL);
					break;
				case TURN_3:
				case TURN_5:
					printf("    %c %c    ", VERTICAL, VERTICAL);
					break;
				case TURN_4:
					printf("     %c     ", VERTICAL);
					break;
				case TURN_6:
					printf("   %c %c %c   ", VERTICAL, image, VERTICAL);
					break;
				case TURN_7:
					printf("  %c  %c  %c  ", VERTICAL, image, VERTICAL);
					break;
				case SHOWN:
					printf(" %c   %c   %c ", VERTICAL, image, VERTICAL);
					break;
			}
			break;
		case 4: // bottom line
			switch (state) {
				case INVISIBLE:
				case TURN_4:
					printf("           ");
					break;
				case HIDDEN:
				case SHOWN:
					printf(" %c%c%c%c%c%c%c%c%c ", BOTTOM_LEFT, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, BOTTOM_RIGHT);
					break;
				case TURN_1:
				case TURN_7:
					printf("  %c%c%c%c%c%c%c  ", BOTTOM_LEFT, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, BOTTOM_RIGHT);
					break;
				case TURN_2:
				case TURN_6:
					printf("   %c%c%c%c%c   ", BOTTOM_LEFT, HORIZONTAL, HORIZONTAL, HORIZONTAL, BOTTOM_RIGHT);
					break;
				case TURN_3:
				case TURN_5:
					printf("    %c%c%c    ", BOTTOM_LEFT, HORIZONTAL, BOTTOM_RIGHT);
					break;
			}
			break;
	}
}