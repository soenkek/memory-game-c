//#include <time.h>
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
}


void validateGameInput() {
	int c_v, c_h;
	getGameInput(&c_v, &c_h);
	animate(c_v, c_h, cards);
}

void generateCards() {
	for (int i = 0; i < FIELD_SIZE; ++i) {
		for (int j = 0; j < FIELD_SIZE; ++j)
		{
			cards[i][j].image = 66;
			cards[i][j].animationState = 0;
			cards[i][j].visibility = 1;
		}
	}
/*
*	srand(time(NULL));
*	int numChars = FIELD_SIZE * FIELD_SIZE / 2;
*	int *chars = (int*) malloc (numChars * sizeof(int));
*	int i = 0;
*	while(1) {
*		for (; i < numChars; ++i)
*		{
*			int ascii = rand() / 25 + 65;
*		}
*		int lastChar = chars[0];
*		for (int j = 1; j < numChars; ++j)
*		{
*			for (int k = j + 1; k < numChars; ++k)
*			{
*				if(chars[j] == chars[k]) {
*					i = j;
*					break;
*				}
*			}
*			if (j == numChars - 1)
*			{
*				for (int l = 0; l < FIELD_SIZE; ++l)
*				{
*					for (int m = 0; m < FIELD_SIZE; ++m)
*					{
*						//save num to 2 random places
*					}
*				}
*				return;
*			}
*		}
*	}
*/
}
