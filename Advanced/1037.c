#include <stdio.h>
#include <stdlib.h>

#define Nmax 100001
#define iptr(ptr) ((int*)ptr)
#define elsize(v) (sizeof v[0])
#define length(begin, end) (end - begin)
#define sort(lo, hi, cmp) qsort(lo, length(lo, hi), elsize(lo), cmp)

int Vc[Nmax], Vp[Nmax], getback;
int cmp(const void *a, const void *b) { return *iptr(a) - *iptr(b); }


int main()
{
    int Nc, Np;
    scanf("%d", &Nc);
    for (int i = 0; i < Nc; ++i)
        scanf("%d", &Vc[i]);
    scanf("%d", &Np);
    for (int i = 0; i < Np; ++i)
        scanf("%d", &Vp[i]);

    sort(Vc, &Vc[Nc], cmp);
    sort(Vp, &Vp[Np], cmp);
    // printf("%p, %p, %d\n", Vc, &Vc[Nc], &Vc[Nc] - Vc);

    for (int i = 0, j = 0; Vc[i] < 0 && Vp[j] < 0; ++i, ++j)
        getback += Vc[i] * Vp[j];
    while (Vc[--Nc] > 0 && Vp[--Np] > 0)
        getback += Vc[Nc] * Vp[Np];

    printf("%d", getback);

    return 0;
}
