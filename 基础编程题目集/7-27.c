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
    int last = n - 1;
    for (int i = 0; i < n; ++i)
        printf("%d%c", v[i], i == last ? '\n' : ' ');
}

// 这道题描述有问题
void bubble(int v[], int n, int k)
{
    for (int i = n - 1; i >= k; --i)
        for (int j = i - 1; j >= 0; --j)
            if (v[i] < v[j]) {
                int tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
}