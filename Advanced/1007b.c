#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main()
{
    int K;
    scanf("%d", &K);
    int mini, maxi, first, current, maymin;
    int maxSum = -1, tempSum = 0;
    bool allnegative = true;

    for (int i = 0; i < K; ++i) {
        scanf("%d", &current);
        if (i == 0)
            first = current;
        if (tempSum == 0 && current > 0)
            maymin = current;

        tempSum += current;
        allnegative = allnegative && (current < 0);

        if (tempSum > maxSum) {
            maxSum = tempSum;
            mini = maymin;
            maxi = current;
        }
        else if (tempSum < 0)
            tempSum = 0;
    }
    if (allnegative) {
        mini = first;
        maxi = current;
    }
    if (maxSum < 0) maxSum = 0;

    printf("%d %d %d\n", maxSum, mini, maxi);
}
