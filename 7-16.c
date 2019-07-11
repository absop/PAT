#include <stdio.h>


int main()
{
    int start, end, cnt = 0;
    scanf("%d", &start);
    end = start + 4;
    for (int i = start; i < end; ++i) {
        for (int j = start; j < end; ++j) {
            if (j == i)continue;
            for (int k = start; k < end; ++k) {
                if (k == i || k == j)
                    continue;
                printf("%d%d%d", i, j, k);
                ++cnt;
                printf(cnt % 6 == 0 ? "\n" : " ");
            }
        }
    }
}
