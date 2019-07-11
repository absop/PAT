#include <stdio.h>
#include <stdbool.h>

#define MAXN 1000000


int reverse(int num, int radix)
{
    int bit[32], i = 0, b = 1;
    while (num > 0) {
        bit[i++] = num % radix;
        num /= radix;
    }
    while (--i >= 0) {
        num += bit[i] * b;
        b *= radix;
    }

    return num;
}

bool isprime[MAXN] = {[2 ... (MAXN - 1)] = true};

void init()
{
    for (int i = 4; i < MAXN; i += 2)
        isprime[i] = false;
    for (int i = 3; i * i < MAXN; i += 2) {
        if (isprime[i]) {
            int j = i * i;
            while (j < MAXN) {
                isprime[j] = false;
                j += 2 * i;
            }
        }
    }
}

int main()
{

    int a, b, radix, ans;
    char *responses[] = {"No", "Yes"};

    init();

    while (scanf("%d", &a), a >= 0) {
        scanf("%d", &radix);
        b = reverse(a, radix);
        ans = isprime[a] && isprime[b];
        printf("%s\n", responses[ans]);
    }

    return 0;
}
