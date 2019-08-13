#include <stdio.h>
#include <string.h>

const char *spell[10] = {
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine"
};

void print(int n)
{
    if (n > 9) {
        print(n / 10);
        putchar(32);
    }
    printf("%s", spell[n % 10]);
}

int main()
{
    int sum = 0;
    char integer[200];

    scanf("%s", integer);
    for (int i = 0; integer[i]; ++i)
        sum += (integer[i] - '0');

    print(sum);
}
