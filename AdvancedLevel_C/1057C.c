#include <stdio.h>
#include <stdlib.h>
// 过不了，难道除了树状数组+二分查找
// 就没有其他方法能够全部通过这道题？

#define MAXN 100001

int stack[MAXN], count[MAXN];

int getnth(int nth)
{
    int i, cnt = 0;
    for (i = 0; i < MAXN; ++i) {
        cnt += count[i];
        if (cnt >= nth)
            return i;
    }
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
                        count[num]--;
                    }
                    else
                        num = getnth((top + 1) / 2);
                    printf("%d\n", num);
                }
                else
                    printf("Invalid\n");
                break;
            case 'u':
                scanf("%d", &num);
                stack[top++] = num;
                count[num]++;
                break;
        }
    }

    return 0;
}
