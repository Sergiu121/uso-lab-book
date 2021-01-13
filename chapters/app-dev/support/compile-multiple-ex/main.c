#include <stdio.h>
#include "lottery.h"

static int sanitize_input(int *guessed)
{
	if (guessed[0] < 1 || guessed[0] > 49) {
		return 0;
	}

	if (guessed[1] < 1 || guessed[1] > 49) {
		return 0;
	}

	if (guessed[2] < 1 || guessed[2] > 49) {
		return 0;
	}

	if (guessed[3] < 1 || guessed[3] > 49) {
		return 0;
	}

	if (guessed[4] < 1 || guessed[4] > 49) {
		return 0;
	}

	if (guessed[5] < 1 || guessed[5] > 49) {
		return 0;
	}

	return 1;
}

int main(void)
{
	int *winning;
	int guessed[6];

	printf("gimme 6 lucky numbers from 1 to 49: ");
	scanf("%d %d %d %d %d %d", &guessed[0], &guessed[1], &guessed[2],
				   &guessed[3], &guessed[4], &guessed[5]);

	if (!sanitize_input(guessed)) {
		printf("wrong input... exiting");
		return 1;
	}

	winning = get_winning();
	if (is_winner(winning, guessed)) {
		printf("congrats!\n");
	} else {
		printf("not today, bud\n");
	}

	return 0;
}
