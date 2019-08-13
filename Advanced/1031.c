#include <stdio.h>
#include <string.h>

int main()
{
    char c[81];
    scanf("%s", c);
    int n = strlen(c) - 1;
    int n1 = n / 3, n2 = (n + 1) - 2 * n1;
    for (int i = 0; i < n1; i++)
        printf("%c%*c%c\n", c[i], n2 - 2, 32, c[n - i]);
    c[n1 + n2] = 0;
    printf("%s\n", c + n1);

    return 0;
}
