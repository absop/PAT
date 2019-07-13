#include <stdio.h>
#include <stdbool.h>


int main()
{
    int number, base;
    int palindromic = true;
    int memory[64] = {0}, len = 0;
    scanf("%d %d", &number, &base);

    while (number > 0) {
        memory[len++] = number % base;
        number /= base;
    }
    for (int i = 0; i < len; ++i) {
        if (memory[i] != memory[len - i - 1]) {
            palindromic = false;
            break;
        }
    }
    printf("%s\n", palindromic ? "Yes" : "No");
    printf("%d", memory[--len]);
    while (--len >= 0)
        printf(" %d", memory[len]);
}
