#include <stdio.h>
#include <string.h>

void parse(char *out, char *in, int n)
{
    char *pdot, *p;

    for (pdot = in; *pdot != 0 && *pdot != '.'; ++pdot);
    for (p = in; *p == '0' || *p == '.'; ++p);
    int cnt = 0, exponent = pdot - p + (pdot < p);
    if (*p == 0) exponent = 0;

    out += sprintf(out, "0.");
    for (; *p && cnt < n; ++p) {
        if (*p != '.') {
            *out++ = *p;
            ++cnt;
        }
    }
    for (; cnt < n; ++cnt) *out++ = '0';

    sprintf(out, "*10^%d", exponent);
}

int main()
{
    int N;
    char inA[128], inB[128], outA[128], outB[128];
    scanf("%d %s %s", &N, inA, inB);

    parse(outA, inA, N);
    parse(outB, inB, N);

    if (!strcmp(outA, outB))
        printf("YES %s\n", outA);
    else
        printf("NO %s %s\n", outA, outB);

    return 0;
}
