#include <stdio.h>
#include <string.h>

int main()
{
    char digit[32], exist[32] = {0};
    scanf("%s", digit);
    int len = strlen(digit);

    for (int i = 0; i < len; ++i) {
        digit[i] -= '0';
        exist[digit[i]] += 1;
    }
    int ok, carry = 0;
    for (int i = len - 1; i >= 0; --i) {
        digit[i] = digit[i] * 2 + carry;
        carry = digit[i] / 10;
        digit[i] %= 10;
        exist[digit[i]] -= 1;
    }
    ok = !carry;
    for (int i = 0; i < len; ++i) {
        if (!ok || exist[digit[i]]) {
            ok = 0;
            break;
        }
    }

    printf(ok ? "Yes\n" : "No\n");
    if (carry) putchar(carry + '0');
    for (int i = 0; i < len; ++i)
        putchar(digit[i] + '0');

    return 0;
}
