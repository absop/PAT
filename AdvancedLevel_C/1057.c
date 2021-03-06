#include <stdio.h>
#include <string.h>

#define MAXN 100010
#define lowbit(i) ((i) & (-i))

int C[MAXN], stack[MAXN];

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
// O(logN ^ 2)
int search(int left, int right, int k)
{
    while (left < right) {
        int mid = (left + right) / 2;
        if (getsum(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main()
{
    int n, num, top = 0;
    char command[16];
#ifdef __TINYC__
    freopen("1057.txt", "w+", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", command);
        switch (command[1]) {
            case 'e':
            case 'o':
                if (top > 0) {
                    if (command[1] == 'o') {
                        num = stack[--top];
                        update(num, -1);
                    }
                    else
                        num = search(1, MAXN, (top + 1) / 2);
                    printf("%d\n", num);
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
