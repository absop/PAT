#include <stdio.h>

int count[100001];
int order[100001];

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &order[i]);
        count[order[i]]++;
    }
    for (int i = 0; i < N; ++i) {
        if (count[order[i]] == 1) {
            printf("%d\n", order[i]);
            return 0;
        }
    }
    printf("None\n");
    return 0;
}
