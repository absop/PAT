#include<stdio.h>

int time_add(int cur, int delta);

int main()
{
    int cur, delta, end;
    scanf("%d %d", &cur, &delta);
    end = time_add(cur, delta);
    printf("%d\n", end);
}

int time_add(int cur, int delta)
{
    int h, m;
    h = cur / 100;
    m = cur % 100 + delta;

    h += m / 60;
    h %= 24;
    m %= 60;
    if (h < 0) {
        h += 24;
    }
    if (m < 0) {
        h -= 1;
        m += 60;
    }

    return 100 * h + m;
}