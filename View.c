#include "View.h"

char *frameBuffer;

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
	int index = 0;
	for (int c_v = 0; c_v < FIELD_SIZE; ++c_v) // cards vertical
	{
		for (int line = 0; line < 5; ++line) // lines height of a card
		{
			for (int c_h = 0; c_h < FIELD_SIZE; ++c_h) // cards horizontally
			{
				printPart(line, cards[c_v][c_h].animationState, cards[c_v][c_h].image, index);
				index += CARD_SIZE_HORIZONTAL;
			}
			buffer(index, 1, "\n");
			index++;
		}
		buffer(index, 1, "\n");
		index++;
	}
	system("cls");
	printf("%s", frameBuffer);
	printf("\nSpieler1: %d\nSpieler2: %d\n\nSpieler%d ist am Zug!\n", points[0], points[1], player + 1);
}

void allocBuffer() {
	int size = FIELD_SIZE * FIELD_SIZE * CARD_SIZE_HORIZONTAL * CARD_SIZE_VERTICAL + FIELD_SIZE * (CARD_SIZE_VERTICAL + 1);
	frameBuffer = malloc((size + 1) * sizeof(char));
	for (int i = 0; i < size; ++i)
		frameBuffer[i] = ' ';
	frameBuffer[size] = '\0';
}

void freeBuffer() {
	free(frameBuffer);
}

void buffer(int startIndex, int length, char *string) {
	for (int i = 0; i < length; ++i)
	{
		if (string[i] == '\0') {
			frameBuffer[startIndex + i] = ' ';
		}
		else
			frameBuffer[startIndex + i] = string[i];
	}
}

void printPart(int line, int state, int image, int startIndex) {
	char string[CARD_SIZE_HORIZONTAL];
	switch (line) {
		case 0: // top line
			switch (state) {
				case INVISIBLE:
				case TURN_4:
					snprintf(string, CARD_SIZE_HORIZONTAL, "           ");
					break;
				case HIDDEN:
				case SHOWN:
					snprintf(string, CARD_SIZE_HORIZONTAL, " %c%c%c%c%c%c%c%c%c ", TOP_LEFT, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, TOP_RIGHT);
					break;
				case TURN_1:
				case TURN_7:
					snprintf(string, CARD_SIZE_HORIZONTAL, "  %c%c%c%c%c%c%c  ", TOP_LEFT, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, TOP_RIGHT);
					break;
				case TURN_2:
				case TURN_6:
					snprintf(string, CARD_SIZE_HORIZONTAL, "   %c%c%c%c%c   ", TOP_LEFT, HORIZONTAL, HORIZONTAL, HORIZONTAL, TOP_RIGHT);
					break;
				case TURN_3:
				case TURN_5:
					snprintf(string, CARD_SIZE_HORIZONTAL, "    %c%c%c    ", TOP_LEFT, HORIZONTAL, TOP_RIGHT);
					break;
			}
			break;
		case 1: // upper mid
		case 3: //lower mid
			switch (state) {
				case INVISIBLE:
					snprintf(string, CARD_SIZE_HORIZONTAL, "           ");
					break;
				case HIDDEN:
				case SHOWN:
					snprintf(string, CARD_SIZE_HORIZONTAL, " %c       %c ", VERTICAL, VERTICAL);
					break;
				case TURN_1:
				case TURN_7:
					snprintf(string, CARD_SIZE_HORIZONTAL, "  %c     %c  ", VERTICAL, VERTICAL);
					break;
				case TURN_2:
				case TURN_6:
					snprintf(string, CARD_SIZE_HORIZONTAL, "   %c   %c   ", VERTICAL, VERTICAL);
					break;
				case TURN_3:
				case TURN_5:
					snprintf(string, CARD_SIZE_HORIZONTAL, "    %c %c    ", VERTICAL, VERTICAL);
					break;
				case TURN_4:
					snprintf(string, CARD_SIZE_HORIZONTAL, "     %c     ", VERTICAL);
					break;
			}
			break;
		case 2: // mid
			switch (state) {
				case INVISIBLE:
					snprintf(string, CARD_SIZE_HORIZONTAL, "           ");
					break;
				case HIDDEN:
					snprintf(string, CARD_SIZE_HORIZONTAL, " %c   ?   %c ", VERTICAL, VERTICAL);
					break;
				case TURN_1:
					snprintf(string, CARD_SIZE_HORIZONTAL, "  %c  ?  %c  ", VERTICAL, VERTICAL);
					break;
				case TURN_2:
					snprintf(string, CARD_SIZE_HORIZONTAL, "   %c ? %c   ", VERTICAL, VERTICAL);
					break;
				case TURN_3:
				case TURN_5:
					snprintf(string, CARD_SIZE_HORIZONTAL, "    %c %c    ", VERTICAL, VERTICAL);
					break;
				case TURN_4:
					snprintf(string, CARD_SIZE_HORIZONTAL, "     %c     ", VERTICAL);
					break;
				case TURN_6:
					snprintf(string, CARD_SIZE_HORIZONTAL, "   %c %c %c   ", VERTICAL, image, VERTICAL);
					break;
				case TURN_7:
					snprintf(string, CARD_SIZE_HORIZONTAL, "  %c  %c  %c  ", VERTICAL, image, VERTICAL);
					break;
				case SHOWN:
					snprintf(string, CARD_SIZE_HORIZONTAL, " %c   %c   %c ", VERTICAL, image, VERTICAL);
					break;
			}
			break;
		case 4: // bottom line
			switch (state) {
				case INVISIBLE:
				case TURN_4:
					snprintf(string, CARD_SIZE_HORIZONTAL, "           ");
					break;
				case HIDDEN:
				case SHOWN:
					snprintf(string, CARD_SIZE_HORIZONTAL, " %c%c%c%c%c%c%c%c%c ", BOTTOM_LEFT, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, BOTTOM_RIGHT);
					break;
				case TURN_1:
				case TURN_7:
					snprintf(string, CARD_SIZE_HORIZONTAL, "  %c%c%c%c%c%c%c  ", BOTTOM_LEFT, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, HORIZONTAL, BOTTOM_RIGHT);
					break;
				case TURN_2:
				case TURN_6:
					snprintf(string, CARD_SIZE_HORIZONTAL, "   %c%c%c%c%c   ", BOTTOM_LEFT, HORIZONTAL, HORIZONTAL, HORIZONTAL, BOTTOM_RIGHT);
					break;
				case TURN_3:
				case TURN_5:
					snprintf(string, CARD_SIZE_HORIZONTAL, "    %c%c%c    ", BOTTOM_LEFT, HORIZONTAL, BOTTOM_RIGHT);
					break;
			}
			break;
	}
	buffer(startIndex, CARD_SIZE_HORIZONTAL, string);
}