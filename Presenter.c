#include <stdio.h>
#include <windows.h>
#include <time.h>

#define FIELD_SIZE  4

typedef struct {
	int image;
	int animationState; // [0...6]
	int visibility; // 1 = visible; 0 = invisible
} FieldProperties;

FieldProperties (*cards)[FIELD_SIZE];

int validateGameInput(int c_v, int c_h);
void generateCards();

int main() {
	cards = malloc (FIELD_SIZE * sizeof(FieldProperties));
	printField();
	while(1) {
	getGameInput();
	}
}

int validateGameInput(int c_v, int c_h) {
	return 1;
}

void generateCards() {
	srand(time(NULL));
	int numChars = FIELD_SIZE * FIELD_SIZE / 2;
	int *chars = (int*) malloc (numChars * sizeof(int));
	int i = 0;
	while(1) {
		for (; i < numChars; ++i)
		{
			int ascii = rand() / 25 + 65;
		}
		int lastChar = chars[0];
		for (int j = 1; j < numChars; ++j)
		{
			for (int k = j + 1; k < numChars; ++k)
			{
				if(chars[j] == chars[k]) {
					i = j;
					break;
				}
			}
			if (j == numChars - 1)
			{
				for (int l = 0; l < FIELD_SIZE; ++l)
				{
					for (int m = 0; m < FIELD_SIZE; ++m)
					{
						//save num to 2 random places
					}
				}
				return;
			}
		}
	}
}