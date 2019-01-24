#include <time.h>
#include <stdlib.h>
#include "View.h"
#include "data_structures.h"
#include <windows.h>

FieldProperties (*cards)[FIELD_SIZE];
//FieldProperties cards[FIELD_SIZE][FIELD_SIZE];
int player;
int *points;

void validateGameInput();
void generateCards();
void compareCards();

int main() {
	player = 0;
	points = malloc (2 * sizeof(int));
	points[0] = points[1] = 0;
	cards = malloc (FIELD_SIZE * FIELD_SIZE * sizeof(FieldProperties));
	generateCards();
	printField(cards, points, player);
	int c_v1; 
	int c_h1; 
	int c_v2; 
	int c_h2;
	//int *removedCards2Dim = (int *)malloc(FIELD_SIZE * FIELD_SIZE * sizeof(int)); 
	while(1) {
		//assign a different value to every cordinate to avoid conflict in validate game input
		c_v1 = 0; c_h1 = 1; c_v2 = 2; c_h2 = 3;
		getGameInput(&c_v1, &c_h1);
		validateGameInput(&c_v1, &c_h1);
		getGameInput(&c_v2, &c_h2);
		validateGameInput(&c_v2, &c_h2);
		compareCards(&c_v1, &c_h1, &c_v2, &c_h2, *cards);
	}
	return 0;
}

void compareCards(int *card1_x, int *card1_y, int *card2_x, int *card2_y, FieldProperties (*cards)[FIELD_SIZE]){
	if (*card1_x == *card2_x && *card1_y == *card2_y){
		animate(*card2_x, *card2_y, cards, points, player);
		printField(cards, points, player);
		printf("You cant select the same card twice. Please select your second card again.");
		getGameInput(card2_x, card2_y);
		validateGameInput(card2_x,card2_y);
		compareCards(card1_x, card1_y, card2_x, card2_y, cards);
	}
	else if (cards[*card1_x][*card1_y].image == cards[*card2_x][*card2_y].image){
		Sleep(800);
		points[player] += 1;
		cards[*card1_x][*card1_y].animationState = -1;
		cards[*card2_x][*card2_y].animationState = -1;
		printField(cards, points, player);
	
	}
	else{
		Sleep(800);
		if (player == 1)
			player = 0;
		else
			player = 1;
		animate(*card1_x, *card1_y, cards, points, player);
		animate(*card2_x, *card2_y, cards, points, player);
	}
}

void validateGameInput(int *c_v,int *c_h) {
	if ((*c_v == 0 || *c_v == 1 || *c_v == 2 || *c_v == 3) && (*c_h == 0 || *c_h == 1 || *c_h == 2 || *c_h == 3 ))	{
		animate(*c_v, *c_h, cards, points, player);
	}else{
		printf("Input not in valid range. Input 2 numbers from 0 to (including) 3 seperated with space \n");
		getGameInput(c_v, c_h);
		validateGameInput(c_v, c_h);
	}
	
}

void generateCards() {
	//initialize cards with defaults
	for (int i = 0; i < FIELD_SIZE; ++i) {
		for (int j = 0; j < FIELD_SIZE; ++j)
		{
			cards[i][j].image = -1;
			cards[i][j].animationState = 0;
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