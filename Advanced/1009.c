#include <stdio.h>

struct _item {
    int expo;
    double coef;
} A[10], B[10], C[100];

double V[2001];

int main()
{
    int Ka, Kb, Kc = 0;

    scanf("%d", &Ka);
    for (int i = 0; i < Ka; ++i)
        scanf("%d %lf", &A[i].expo, &A[i].coef);

    scanf("%d", &Kb);
    for (int i = 0; i < Kb; ++i) {
        scanf("%d %lf", &B[i].expo, &B[i].coef);
        for (int j = 0; j < Ka; ++j) {
            int expo = B[i].expo + A[j].expo;
            V[expo] += B[i].coef * A[j].coef;
        }
    }
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
