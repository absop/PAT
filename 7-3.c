#include<stdio.h>

void reserve_print(int n);

int main()
{
    int num;
    scanf("%d", &num);
    reserve_print(num);
    return 0;
}

void reserve_print(int n)
{
    while ( n % 10 == 0) n /= 10;
    while (n > 0) {
        printf("%d", n % 10);
        n /= 10;
    }
}