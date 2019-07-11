#include <stdio.h>

void print_range(int begin, int end);

int main()
{
    int begin, end;
    scanf("%d %d", &begin, &end);
    print_range(begin, end);
    printf("Sum = %d\n", (begin + end) * (end - begin + 1) / 2);
}

void print_range(int begin, int end)
{
    int i, j, cnt = 0;
    for (i = begin; i <= end; ++i) {
        printf("%5d", i);
        cnt += 1;
        if (cnt % 5 == 0)
            printf("\n");
    }
    if (cnt % 5 != 0)
        printf("\n");
}