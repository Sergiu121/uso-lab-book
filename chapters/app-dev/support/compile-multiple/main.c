#include <stdio.h>
#include "algorithms.h"

int main(void)
{
	int n;

	printf("gimme number and i'll give you factorial: ");
	scanf("%d", &n);

	printf("%d! = %u\n", n, factorial(n));
	printf("%d! = %u\n", n + 1, factorial(n + 1));
	return 0;
}
