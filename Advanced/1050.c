#include <stdio.h>
#include <stdio.h>


int main()
{
    char S1[10001];
    char S2[10001];
    char chs[128] = {0};

    int i, j, c;

    gets(S1);
    gets(S2);

    for (i = 0; (c = S2[i]) != 0; ++i)
        chs[c] = 1;
    // memset(S2, 0, 10001);

    j = 0;
    for (i = 0; (c = S1[i]) != 0; ++i) {
        if (!chs[c])
            S2[j++] = c;
    }
    S2[j] = 0;
    puts(S2);
}
