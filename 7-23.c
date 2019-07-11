#include <stdio.h>


/////////////
// 币值转换 //
/////////////


void printDigit(char c, int b)
{
    putchar(c);
    switch (b) {
        case 1: putchar('S'); break;
        case 2: putchar('B'); break;
        case 3: putchar('Q'); break;
        case 4: putchar('W'); break;
        case 5: putchar('S'); break;
        case 6: putchar('B'); break;
        case 7: putchar('Q'); break;
        case 8: putchar('Y'); break;
    }
}


int main()
{
    char inp[16], len = -1;
    scanf("%s", inp);

    while (inp[++len]);
    for (int i = 0; i < len; ++i)
        printDigit(inp[i] + 'a' - '0', len - i - 1);

    printf("\n");

    return 0;
}
