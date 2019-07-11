/* written by 叶芝秋 */
#include <stdio.h>
#include <string.h>

#ifndef __int64
    #define __int64 long long
#endif

// char *charv = "0123456789abcdefghijklmnopqrstuvwxyz";
char vchar[128];

__int64 parse(char *bits, int len, int radix)
{
    __int64 value = 0, bitvalue = 1;
    while (--len >= 0) {
        value += vchar[bits[len]] * bitvalue;
        bitvalue *= radix;
    }
    return value;
}

void init()
{
    for (int i = '0'; i <= '9'; ++i)
        vchar[i] = i - '0';
    for (int i = 'a'; i <= 'z'; ++i)
        vchar[i] = i - 'a' + 10;
}

int main()
{
    char N1[16] = {0}, N2[16] = {0};
    char *N[2] = {N1, N2};
    int tag, radix, klen, ulen;
    __int64 kv, uv;
    __int64 minr, midr, maxr;

    init();

    scanf("%s %s %d %d", N1, N2, &tag, &radix);

    tag -= 1;
    klen = strlen(N[tag]);
    ulen = strlen(N[!tag]);
    kv = parse(N[tag], klen, radix);

    int bitmax = 0;
    for (int i = 0; i < ulen; ++i) {
        if (N[!tag][i] > bitmax)
            bitmax = N[!tag][i];
    }
    minr = vchar[bitmax] + 1;
    maxr = kv + 1;

    while (minr <= maxr) {
        midr = (minr + maxr) >> 1;
        uv = parse(N[!tag], ulen, midr);
        if (uv > kv || uv <= 0)
            maxr = midr - 1;
        else if (uv < kv)
            minr = midr + 1;
        else {
            printf("%lld\n", midr);
            return 0;
        }
    }
    printf("Impossible\n");

    return 0;
}
