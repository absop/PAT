#include <stdio.h>


int main()
{
    int i;
    float float1, float2;
    char c;
    scanf("%f %d %c %f", &float1, &i, &c, &float2);
    printf("%c %d %.2f %.2f\n", c, i, float1, float2);
}