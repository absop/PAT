#include <stdio.h>
#include <string.h>

int main()
{
    int n, len;
    char line[128], bkup[128];
    gets(line);
    scanf("%d", &n);
    len = strlen(line);
    n %= len;
    memcpy(bkup, line, n);
    memcpy(line, line + n, len - n);
    memcpy(line + len - n, bkup, n);
    printf("%s\n", line);

    return 0;
}
