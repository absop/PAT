#include <stdio.h>


int main()
{
    double Open, High, Low, Close;
    scanf("%lf %lf %lf %lf", &Open, &High, &Low, &Close);

    if (Close < Open)
        printf("BW-Solid");
    else if (Close > Open)
        printf("R-Hollow");
    else
        printf("R-Cross");
    if (Low < Open && Low < Close) {
        printf(" with Lower Shadow");
        if (High > Open && High > Close)
            printf(" and Upper Shadow\n");
    }
    else if (High > Open && High > Close)
        printf(" with Upper Shadow\n");
    else
        printf("\n");

}
