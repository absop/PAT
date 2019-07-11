#include <stdio.h>

struct _item {
    int e;
    double c;
} A[10], P[100];

double C[2001];

int main()
{
    int Ka, Kb, e, Kc = 0;
    double c;

    scanf("%d", &Ka);
    for (int i = 0; i < Ka; ++i)
        scanf("%d %lf", &A[i].e, &A[i].c);

    scanf("%d", &Kb);
    for (int i = 0; i < Kb; ++i) {
        scanf("%d %lf", &e, &c);
        for (int j = 0; j < Ka; ++j)
            C[e + A[j].e] += c * A[j].c;
    }
    for (int e = 2000; e >= 0; --e)
        if (C[e] != 0)
            P[Kc++] = (struct _item) {e, C[e]};

    printf("%d", Kc);
    for (int i = 0; i < Kc; ++i)
        printf(" %d %.1lf", P[i].e, P[i].c);
    printf("\n");
}
