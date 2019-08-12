#include <stdio.h>


int main()
{
    double a, bests[3] = {0};
    const char T[] = "WTL";
    char tags[3] = {0};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%lf", &a);
            if (a > bests[i]) {
                bests[i] = a;
                tags[i] = T[j];
            }
        }
    }

    a = (bests[0] * bests[1] * bests[2] * 0.65 - 1) * 2;
    printf("%c %c %c %.2lf\n", tags[0], tags[1], tags[2], a);

    return 0;
}
