#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main()
{
    int cards[54], tobe[54];
    int backup[54], K;
    const char *fmts[2] = { "%c%d", " %c%d" };
    scanf("%d", &K);
    for (int i = 0; i < 54; ++i) {
        scanf("%d", &tobe[i]);
        tobe[i] -= 1;
        cards[i] = i;
    }
    for (int i = 0; i < K; ++i) {
        memcpy(backup, cards, 54 * sizeof (int));
        for (int j = 0; j < 54; ++j)
            cards[tobe[j]] = backup[j];
    }
    for (int i = 0; i < 54; ++i)
        printf(fmts[!!i], "SHCDJ"[cards[i] / 13], cards[i] % 13 + 1);

    return 0;
}
