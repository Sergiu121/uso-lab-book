#include "algorithms.h"

unsigned int factorial(int n)
{
	unsigned int fact = 1;

	while (n > 0) {
		fact *= n;
		n--;
	}

	return fact;
}
