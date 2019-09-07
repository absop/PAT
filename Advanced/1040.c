#include <stdio.h>

int main()
{
    int longest = 1;
    char line[1024] = {0};
    gets(line + 1); /* line[0] as sentinel */

    char *lo, *hi;
    for (char *p = line + 1; *p; ++p) {
        for (lo = p; *lo == *p; --lo);
        for (hi = p; *hi == *p; ++hi);
        for (; *lo == *hi && *lo && *hi; --lo, ++hi);
        if (hi - lo - 1 > longest) longest = hi - lo - 1;
    }
    printf("%d\n", longest);

    return 0;
}
