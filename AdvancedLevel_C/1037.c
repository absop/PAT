#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000
#define sort(lo, hi, cmp) qsort(lo, hi - lo, sizeof lo[0], cmp)
#define iptr(ptr) ((int*)ptr)
#define cvptr const void *
int cmp(cvptr a, cvptr b) { return *iptr(a) - *iptr(b); }

int Vc[MAXN + 1], Vp[MAXN + 1], getback;

int main()
{
    int Nc, Np;
    scanf("%d", &Nc);
    for (int i = 0; i < Nc; ++i)
        scanf("%d", &Vc[i]);
    scanf("%d", &Np);
    for (int i = 0; i < Np; ++i)
        scanf("%d", &Vp[i]);

    sort(Vc, Vc + Nc, cmp);
    sort(Vp, Vp + Np, cmp);

    for (int i = 0, j = 0; Vc[i] < 0 && Vp[j] < 0; ++i, ++j)
        getback += Vc[i] * Vp[j];
    while (Vc[--Nc] > 0 && Vp[--Np] > 0)
        getback += Vc[Nc] * Vp[Np];

    printf("%d", getback);

    return 0;
}
