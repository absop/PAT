#include <stdio.h>


int main()
{
    int len;
    char s[16], *b = "YQBSWQBS";
    scanf("%s", s);
    for (len = 0; s[len]; ++len);
    b += 9 - len;
    if (s[0] == '0') {
        putchar('a');
        return 0;
    }
    for (int j = 0, i = 0; i < len; i++) {
        s[i] += 'a' - '0';
        if (s[i] == 'a') {
            if (5 < len && len < 9 && len - i == 5)
                putchar('W');
            continue;
        }
        if (i - j > 1) putchar('a');
        putchar(s[i]);
        putchar(b[i]);
        j = i;
    }

    return 0;
}
