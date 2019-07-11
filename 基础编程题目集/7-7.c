#include<stdio.h>


int T(int hour) { return hour <= 12 ? hour : hour % 12; }
char *D(int hour) { return hour < 12 ? "AM" : "PM"; }

int main()
{
    int hour, minu;
    scanf("%d:%d", &hour, &minu);
    printf("%d:%d %s\n", T(hour), minu, D(hour));
    return 0;
}
