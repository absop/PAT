#include <stdio.h>

/////////////
// 龟兔赛跑 //
/////////////

int main()
{
    int T, w = 0, t = 0;
    scanf("%d", &T);

    w = 3 * T;
    for (int i = 0; ;) {
        if (t > 3 * i) {
            i += 30;
            if (i >= T)
                break;
        }
        else {
            if ((T - i) < 10) {
                t += (T - i) * 9;
                break;
            }
            t += 90;
            i += 10;
        }
    }

    if (w > t)      printf("@_@ %d\n", w);
    else if (t > w) printf("^_^ %d\n", t);
    else            printf("-_- %d\n", t);
}
