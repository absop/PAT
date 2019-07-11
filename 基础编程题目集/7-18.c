#include <stdio.h>

#define abs(a) ((a) >= 0 ? (a): (-(a)))
#define F(x) (x * (x * (a3 * x + a2) + a1) + a0)

int main()
{
    float a3, a2, a1, a0, a, b, x0, y0;
    scanf("%f %f %f %f", &a3, &a2, &a1, &a0);
    scanf("%f %f", &a, &b);

    do {
        x0 = (a + b) / 2;
        y0 = F(x0);
        if (abs(y0) < 1e-3) break;
        else if (y0 * F(a) > 0)a = x0;
        else if (y0 * F(b) > 0)b = x0;
    }
    while (abs(b - a) > 1e-3);

    printf("%.2f\n", x0);

    return 0;
}

