#include <stdio.h>

int check_if_prime(int n)
{
    int i;

    for (i = 2; i < n / 2; i++) {
        if (n % i) {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    int n;

    printf("Please gimme a number: ");
    scanf("%d", &n);
    
    if (check_if_prime(n)) {
        printf("%d is prime\n", n);
    } else {
        printf("%d is not prime\n", n);
    }

    return 0;
}
