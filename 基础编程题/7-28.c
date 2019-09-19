#include <stdio.h>
#include <stdbool.h>

bool incircle[1000] = {[0 ... 999] = true};

int main()
{
    int n, cnt, it;
    scanf("%d", &n);
    cnt = n;
    for (int j = 0, i = 0; cnt > 1; i = (i + 1) % n) {
        if (incircle[i]) {
            j++;
            if (j % 3 == 0) {
                incircle[i] = false;
                --cnt;
            }
            else it = i;
        }
    }
    printf("%d\n", it + 1);
}
