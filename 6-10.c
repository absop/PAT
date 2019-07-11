#include <stdio.h>


void Print_Factorial(const int N);

int main()
{
    Print_Factorial(1000);
    return 0;
}

// 10^9 < typemax(int)
#define SCALE 1000000

void Print_Factorial(const int N)
{
    if (N < 0 || N > 1000) {
        printf("Invalid input\n");
        return;
    }
    int i, j, carry, len;
    int fac[500] = {0};
    j = len = 0; fac[0] = 1;

    for (int n = 2; n <= N; ++n) {
        i = j; carry = 0;
        while (i <= len) {
            carry += n * fac[i];
            fac[i] = carry % SCALE;
            carry /= SCALE;
            i++;
        }
        if (fac[j] == 0) ++j;
        if (carry > 0) {
            fac[i] = carry;
            ++len;
        }
    }
    printf("%d", fac[len]);
    while (--len >= 0)
        printf("%06d", fac[len]);
    printf("\n");
}
