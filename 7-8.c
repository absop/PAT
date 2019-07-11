#include <stdio.h>


int main()
{
    int speed;
    scanf("%d", &speed);
    printf("Speed: %d - %s\n", speed, speed > 60 ? "Speeding" : "OK");
}