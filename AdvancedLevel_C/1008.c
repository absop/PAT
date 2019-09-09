#include <stdio.h>
#include <string.h>


int main()
{
    int N, tt, next, curr = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &next);
        int d = next - curr;
        int cost = d >= 0 ? 6 : -4;
        tt += (d * cost + 5);
        curr = next;
    }
    printf("%d\n", tt);
}
