#include <stdio.h>

int main()
{
    char N1[16], N2[16], *p, *pk = N1, *pu = N2;
    long long kv, uv, minr, midr, maxr, vchr[128] = {0};
    for (int i = '0'; i <= '9'; ++i) vchr[i] = i - '0';
    for (int i = 'a'; i <= 'z'; ++i) vchr[i] = i - 'a' + 10;
    
    scanf("%s %s %lld %lld", N1, N2, &kv, &uv);
    if (kv == 2) pk = N2, pu = N1;
    for (p = pk, kv = vchr[*p]; *++p; kv = kv * uv + vchr[*p]);
    for (p = pu, minr = *p; *++p; *p > minr && (minr = *p));
    for (minr = vchr[minr] + 1, maxr = kv + 1; minr <= maxr;) {
        midr = (minr + maxr) >> 1;
        for (p = pu, uv = vchr[*p]; *++p; uv = uv * midr + vchr[*p]);
        if (uv > kv || uv <= 0) maxr = midr - 1;
        else if (uv < kv) minr = midr + 1;
        else break;
    }
    uv == kv && printf("%lld\n", midr);
    uv != kv && printf("Impossible\n");
    return 0;
}
