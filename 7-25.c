#include <stdio.h>

#define abs(num) ((num) >= 0 ? (num): -(num))
void spell(int num);

int main()
{
    spell(-1312245);
    printf("\n");
    spell(0);
    printf("\n");
    // int num;
    // scanf("%d", &num);
    // spell(num);

    return 0;
}

void print_digit(int d)
{
    switch (d) {
        case 0: printf("ling"); break;
        case 1: printf("yi");   break;
        case 2: printf("er");   break;
        case 3: printf("san");  break;
        case 4: printf("si");   break;
        case 5: printf("wu");   break;
        case 6: printf("liu");  break;
        case 7: printf("qi");   break;
        case 8: printf("ba");   break;
        case 9: printf("jiu");  break;
    }
}

void spell(int num)
{
    if (abs(num) < 10) {
        if (num < 0)
            printf("fu ");
        print_digit(abs(num));
    }
    else {
        spell(num / 10);
        putchar(' ');
        print_digit(abs(num % 10));
    }
}