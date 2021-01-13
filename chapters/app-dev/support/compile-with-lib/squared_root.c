#include <stdio.h>
#include <math.h>

int main(void)
{
	int n;

	printf("gimme a number and i'll give its square root: ");
	scanf("%d", &n);

	printf("here you go: %f\n", sqrt(n));

	return 0;
}
