#include <time.h>
#include <stdlib.h>

#include "lottery.h"

static int cmpfunc(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

int *get_winning()
{
	int i;
	int *winner = malloc (6 * sizeof(int));

	srand(time(NULL));
	for (i = 0; i < 6; i++) {
		winner[i] = rand() % 49 + 1;
	}

	return winner;
}

int is_winner(int *winner, int *guessed)
{
	qsort(winner, 6, sizeof(int), cmpfunc);
	qsort(guessed, 6, sizeof(int), cmpfunc);

	if (winner[0] != guessed[0]) {
		return 0;
	}

	if (winner[1] != guessed[1]) {
		return 0;
	}

	if (winner[2] != guessed[2]) {
		return 0;
	}

	if (winner[3] != guessed[3]) {
		return 0;
	}

	if (winner[4] != guessed[4]) {
		return 0;
	}

	if (winner[5] != guessed[5]) {
		return 0;
	}

	return 1;
}
