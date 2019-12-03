#include <stdio.h>

#define min(x, y) ((x) < (y) ? (x) : (y))

struct mouse {
    int weight, rank;
} mouses[1000], *pmouses[1000];

int Np, Ng;
int ngroup(int n) { return (n + Ng - 1) / Ng; }

int main()
{
    scanf("%d %d", &Np, &Ng);

    for (int i = 0; i < Np; ++i)
        scanf("%d", &mouses[i].weight);
    for (int i = 0; i < Np; ++i) {
        scanf("%d", &mouses[i].rank);
        pmouses[i] = &mouses[mouses[i].rank];
    }
#if 0
    printf("%d", pmouses[0]->weight);
    for (int i = 1; i < Np; ++i)
        printf(" %d", pmouses[i]->weight);
    printf("\n");
#endif
    int newlen, rank, maxi, gend;
    for (int n = Np; n > 1; n = newlen) {
        newlen = ngroup(n);
        rank = newlen + 1;
        for (int i = 0; i < newlen; ++i) {
            maxi = i * Ng;
            gend = min(maxi + Ng, n);
            for (int j = maxi + 1; j < gend; ++j) {
                if (pmouses[j]->weight < pmouses[maxi]->weight)
                    pmouses[j]->rank = rank;
                else {
                    pmouses[maxi]->rank = rank;
                    maxi = j;
                }
            }
            pmouses[i] = pmouses[maxi];
        }
#if 0
        printf("%d", pmouses[0]->weight);
        for (int i = 1; i < newlen; ++i)
            printf(" %d", pmouses[i]->weight);
        printf("\n");
#endif
    }
    pmouses[maxi]->rank = 1;

    printf("%d", mouses[0].rank);
    for (int i = 1; i < Np; ++i)
        printf(" %d", mouses[i].rank);

    return 0;
}
