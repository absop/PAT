/* written by 叶芝秋 */
#include <stdio.h>


int map[1000000];
int ranks[4][102];
int scores[2000][4];
int N, M, id, *ith, rank, course;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        ith = scores[i];
        scanf("%d %d %d %d", &id, &ith[1], &ith[2], &ith[3]);
        ith[0] = (ith[1] + ith[2] + ith[3]) / 3;
        for (int j = 0; j < 4; ++j)
            ranks[j][ith[j]]++;
        map[id] = i + 1;
    }

    // 利用计数排序的方法确定各分数对应的排名
    for (int i = 0; i < 4; ++i) {
        for (int j = 100, t2 = 1; j >= 0; --j) {
            int t1 = t2; t2 = ranks[i][j];
            ranks[i][j] = ranks[i][j + 1] + t1;
        }
    }
    for (int i = 0; i < M; ++i) {
        scanf("%d", &id);
        if (map[id]) {
            ith = scores[map[id] - 1];
            rank = ranks[0][ith[0]];
            course = 'A';
            for (int j = 1; j < 4; ++j) {
                if (ranks[j][ith[j]] < rank) {
                    rank = ranks[j][ith[j]];
                    course = "ACME"[j];
                }
            }
            printf("%d %c\n", rank, course);
        }
        else
            printf("N/A\n");
    }
    return 0;
}
