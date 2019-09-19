#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100], s2[100];
    gets(s1);
    gets(s2);
    int len = strlen(s2);
    for (char *p; p = strstr(s1, s2); ) {
        for (; *p = *(p + len); ++p);
    }
    puts(s1); // 这里不能用 printf, %%

    return 0;
}
