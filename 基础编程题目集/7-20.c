#include <stdio.h>


void print99(int degree)
{
    for (int row = 1; row <= degree; ++row){
        for (int col = 1; col <= row; ++col)
            printf("%d*%d=%-4d", col, row, col * row);
        printf("\n");
    }
}

int main()
{
    int degree;
    scanf("%d", &degree);
    print99(degree);
}

