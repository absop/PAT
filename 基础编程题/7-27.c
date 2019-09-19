#include <stdio.h>

void bubble(int v[], int n, int k);
void input(int v[], int n);
void output(int v[], int n);

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int v[n];
    input(v, n);
    bubble(v, n, k);
    output(v, n);

    return 0;
}

void input(int v[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);
}

void output(int v[], int n)
{
    const char *fmts[2] = { "%d", " %d" };
    for (int i = 0; i < n; ++i)
        printf(fmts[!!i], v[i]);
}

void bubble(int v[], int n, int k)
{
    for (int i = 0; i < k; ++i)
        for (int j = 1; j < n; ++j)
            if (v[j - 1] > v[j]) {
                int tmp = v[j - 1];
                v[j - 1] = v[j];
                v[j] = tmp;
            }
}
