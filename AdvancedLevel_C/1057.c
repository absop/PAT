#include <stdio.h>
#include <string.h>

#define MAXN 100010
#define lowbit(i) ((i) & (-i))

int C[MAXN], stack[MAXN], top;

void update(int x, int v)
{
    for (int i = x; i < MAXN; i += lowbit(i))
        C[i] += v;
}

int getsum(int x)
{
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        sum += C[i];
    return sum;
}

void PeekMedian()
{
    int k = (top + 1) / 2;
    int left = 1, right = MAXN, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (getsum(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    printf("%d\n", left);
}

int main()
{
    int n, num;
    char command[16];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", command);
        switch (command[1]) {
            case 'e':
                if (top > 0)
                    PeekMedian();
                else
                    printf("Invalid\n");
                break;
            case 'o':
                if (top > 0) {
                    update(stack[--top], -1);
                    printf("%d\n", stack[top]);
                }
                else
                    printf("Invalid\n");
                break;
            case 'u':
                scanf("%d", &num);
                stack[top++] = num;
                update(num, 1);
                break;
        }
    }

    return 0;
}
