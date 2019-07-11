#include <stdio.h>


int main()
{
    int years, hours;
    float salary, weekpay;

    scanf("%d %d", &years, &hours);
    weekpay = years >= 5 ? 50 : 30;
    salary = weekpay * hours;
    if (hours > 40)
        salary += 0.5 * weekpay * (hours - 40);
    printf("%.2f\n", salary);
}