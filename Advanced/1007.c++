#include <stdio.h>

int main(void)
{
    int K;
    scanf("%d", &K);
    int array[K];

    for (int i = 0; i < K; i++)
        scanf("%d", &array[i]);

    int tmpSum = 0, maxSum = -1;
    int mini = 0, maxi = K - 1, maymini = 0;

    for (int i = 0; i < K; i++) {
        tmpSum += array[i];
        if (tmpSum < 0) {
            tmpSum = 0;
            maymini = i + 1;
        }
        else if (tmpSum > maxSum) {
            maxSum = tmpSum;
            mini = maymini;
            maxi = i;
        }
    }
    if (maxSum < 0) maxSum = 0;
    printf("%d %d %d", maxSum, array[mini], array[maxi]);

    return 0;
}
