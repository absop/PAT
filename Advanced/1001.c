#include <stdio.h>


int main()
{
    int a, b, sum, sign;
    int j, i = 0;
    char res[16] = {0};

    scanf("%d %d", &a, &b);
    sum = a + b;
    sign = (sum < 0);
    sum = sum >= 0 ? sum : -sum;

    if (sum > 0) {
        res[i++] = '0' + sum % 10;
        sum /= 10;
        for (j = 1; sum > 0; ++j) {
            if (j % 3 == 0)
                res[i++] = ',';
            res[i++] = '0' + sum % 10;
            sum /= 10;
        }
    }
    else
        res[i++] = '0';

    if (sign) putchar('-');
    while (i > 0)
        putchar(res[--i]);

    return 0;
}
