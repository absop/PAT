#include <stdio.h>

typedef struct _item {
    int expo;
    double coef;
} titem;

double V[2001];

int main()
{
    int Ka, Kb, Kc;

    scanf("%d", &Ka);
    titem A[Ka];
    for (int i = 0; i < Ka; ++i)
        scanf("%d %lf", &A[i].expo, &A[i].coef);

    scanf("%d", &Kb);
    titem B[Kb];
    for (int i = 0; i < Kb; ++i)
        scanf("%d %lf", &B[i].expo, &B[i].coef);

    for (int i = 0; i < Ka; ++i)
        for (int j = 0; j < Kb; ++j) {
            int expo = A[i].expo + B[j].expo;
            V[expo] += A[i].coef * B[j].coef;
        }

    titem C[Ka * Kb];
    Kc = 0;
    for (int k = 2000; k >= 0; --k)
        if (V[k]) {
            C[Kc].expo = k;
            C[Kc].coef = V[k];
            Kc++;
        }

    printf("%d", Kc);
    for (int i = 0; i < Kc; ++i)
        printf(" %d %.1lf", C[i].expo, C[i].coef);
    printf("\n");
}
