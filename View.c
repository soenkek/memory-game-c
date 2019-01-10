void getGameInput() {
	int c_v, c_h;
	scanf("%d %d", &c_v, &c_h);
	int valid = validateGameInput(c_v, c_h);
	if (valid == 1) {
		animate(c_v, c_h);
	} else {
		printf("\ninvalid!\n");
		//notify and retry
	}
}

void animate(int c_v, int c_h) {
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
		printField();
	}
}

void printField() {
	system("cls");
	for (int c_v = 0; c_v < FIELD_SIZE; ++c_v) // cards vertical
	{
		for (int line = 0; line < FIELD_SIZE; ++line) // lines height of a card
		{
			for (int c_h = 0; c_h < FIELD_SIZE; ++c_h) // cards horizontally
			{
				printPart(c_v, c_h, line, cards[c_v][c_h].animationState);
			}
			printf("\n");
		}
		printf("\n");
	}
}

void printPart(int c_v, int c_h, int line, int state) {
	switch (line) {
		case 0: // top line
			switch (state) {
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
					printf("  | %s |  ", cards[c_v][c_h].image);
					break;
				case 6:
					printf(" |  %s  | ", cards[c_v][c_h].image);
					break;
			}
			break;
		case 3: // bottom line
			switch (state) {
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