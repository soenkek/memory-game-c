#include <time.h>
#include <stdlib.h>
#include "View.h"
#include "data_structures.h"

//FieldProperties (*cards)[FIELD_SIZE];
FieldProperties cards[FIELD_SIZE][FIELD_SIZE];

void validateGameInput();
void generateCards();

int main() {
	//cards = malloc (FIELD_SIZE * sizeof(FieldProperties));
	generateCards();
	printField(cards);
	while(1) {
		validateGameInput();
	}
	return 0;
}


void validateGameInput() {
	int c_v, c_h;
	getGameInput(&c_v, &c_h);
	animate(c_v, c_h, cards);
}

void generateCards() {
	//initialize cards with defaults
	for (int i = 0; i < FIELD_SIZE; ++i) {
		for (int j = 0; j < FIELD_SIZE; ++j)
		{
			cards[i][j].image = -1;
			cards[i][j].animationState = 0;
			cards[i][j].visibility = 1;
		}
	}
	//generate random numbers
	srand(time(NULL));
	int numChars = FIELD_SIZE * FIELD_SIZE / 2;
	int *chars = (int*) malloc (numChars * sizeof(int));
	int i = 0;
	while(1) {	//generatorLoop
		for (; i < numChars; ++i)
		{
			int ascii = (rand() % 25) + 65;
			chars[i] = ascii;
		}
		//check if unique
		for (int j = 0; j < numChars; ++j) //outer checkLoop
		{
			for (int k = j + 1; k < numChars; ++k) //inner checkLoop
			{
				if(chars[j] == chars[k]) {
					i = j;
					j = k = numChars; //break out of both checkLoops
					break;
				}
			}
		}
		if (i >= numChars)
		{
			break; //break out of generatorLoop
		}
	}
	//put numbers into cards
	for (i = 0; i < numChars; ++i)
	{
		printf("%d\n", i);
		for (int j = 0; j < 2; ++j) //2 cards per image
		{
			int position = rand() % FIELD_SIZE * FIELD_SIZE - 1;
			int x = position/FIELD_SIZE;
			int y = position%FIELD_SIZE;
			while(cards[x][y].image != -1) { //iterate until "empty" card is found
				position++;
				if (position > FIELD_SIZE * FIELD_SIZE - 1) {
					position = 0;
				}
				x = position/FIELD_SIZE;
				y = position%FIELD_SIZE;
			}
			cards[x][y].image = chars[i];
		}
	}
}