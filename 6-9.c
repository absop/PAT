#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;

    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

int Count_Digit ( const int N, const int D )
{
    int cnt = 0, N1 = N;
    do {
        int mod = N1 % 10;
        if (mod == D || mod == -D)
            ++cnt;
        N1 /= 10;
    }
    while (N1 != 0);
    return cnt;
}