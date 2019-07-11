#include <stdio.h>


void input(double polynomial[])
{
    int K, N;
    double a;

    scanf("%d", &K);
    for (int i = 0; i < K; ++i) {
        scanf("%d %lf", &N, &a);
        polynomial[N] = a;
    }
}

int addto(double A[], double B[])
{
    int cnt = 0;
    for (int i = 0; i <= 1000; ++i) {
        A[i] += B[i];
        cnt += (A[i] != 0);
    }

    return cnt;
}

int main()
{
    int K;
    double A[1001] = {0};
    double B[1001] = {0};

    input(A);
    input(B);
    K = addto(A, B);

    printf("%d", K);
    for (int i = 1000; i >= 0; --i) {
        if (A[i] != 0) {
            printf(" %d %.1f", i, A[i]);
            if (--K == 0)
                break;
        }
    }
    printf("\n");

    return 0;
}
