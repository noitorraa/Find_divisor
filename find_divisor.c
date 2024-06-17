#include <stdio.h>

int Division(int a, int b)
{
    int counter = 0;
    while (a > b)
    {
       a -= b;
       counter += 1;
    }
    return counter;
}

int Remainder_of_the_division(int a, int b)
{
    if (a < b)
    {
      return a;
    }
    return Remainder_of_the_division(a-b, b);
}

int Fun(int n)
{
    int i, j, max_divisor = -1;
    for (i = 2; i <= Division(n, 2); i++) {
        if (Remainder_of_the_division(n, i) == 0) {
            int is_prime = 1;
            for (j = 2; j <= Division(i, 2); j++) {
                if (Remainder_of_the_division(i,j) == 0) {
                    is_prime = 0;
                    break;
                }
            }
            if (is_prime && i > max_divisor) {
                max_divisor = i;
            }
        }
    }
    return max_divisor;
}

int main() {
    int n, result;
    scanf("%d", &n);
    if (n < 0){
        n *= -1;
    }
    result = Fun(n);
    if (result != -1) {
        printf("%d", result);
    } else {
        printf("n/a");
    }

    return 0;
}
