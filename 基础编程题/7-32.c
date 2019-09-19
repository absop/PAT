#include <stdio.h>
#include <string.h>

char line[500001];
char *words[250000];

int main()
{
    char c, *p;
    int cnt = 0, seenspace = 1;
    gets(line);
    for (p = line; *p; ++p) {
        if (*p != ' ') {
            if (seenspace)
                words[cnt++] = p;
            seenspace = 0;
        }
        else {
            *p = 0;
            seenspace = 1;
        }
    }
    for (int i = cnt - 1; i >= 0; --i)
        printf(i == cnt - 1 ? "%s" : " %s", words[i]);

    return 0;
}
