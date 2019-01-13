CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -O2

all:
	$(CC) $(CFLAGS) -o Memory.exe Presenter.c