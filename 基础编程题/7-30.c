#include <stdio.h>
#include <string.h>

char buffer[100][12];

int main()
{
    int n, k;
    char *words[100];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s", buffer[i]);
        words[i] = buffer[i];
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 1; j < n - i; ++j) {
            if (strcmp(words[j], words[j - 1]) < 0) {
                char *temp = words[j];
                words[j] = words[j - 1];
                words[j - 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        puts(words[i]);

    return 0;
}
