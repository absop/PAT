#include <stdio.h>


int main()
{
    int bcd;
    scanf("%d", &bcd);
    printf("%d%d\n", bcd / 16, bcd % 16);
}