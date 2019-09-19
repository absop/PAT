#include <stdio.h>
#include <string.h>

int gcd(int p, int q) { return p ? gcd(q % p, p) : q; }
void reduce(int *p, int *q)
{
    int g = gcd(*p, *q);
    *p /= g;
    *q /= g;
}

int main()
{
    int n, m, d, memb, deno;
    scanf("%d/%d", &m, &d);
    scanf("%d/%d", &memb, &deno);
    memb *= d;
    memb += deno * m;
    deno *= d;
    reduce(&memb, &deno);

    printf("%d", memb);
    if (deno != 1) printf("/%d\n", deno);

    return 0;
}
