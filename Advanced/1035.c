#include <stdio.h>
#include <string.h>

int main()
{
    int changed, N, cnt = 0;
    char modified[1000][24], buffer[16] = {32};
    char *password = buffer + 1, *p;
    const char *fmts[2] = {
        "There is %d account %s",
        "There are %d accounts %s"
    };

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s %s", modified[cnt], password);
        for (changed = 0, p = password; *p; ++p) {
            // 1 -> @, 0 -> %, l -> L, O -> o
            if      (*p == '1') { changed = 1; *p = '@'; }
            else if (*p == '0') { changed = 1; *p = '%'; }
            else if (*p == 'l') { changed = 1; *p = 'L'; }
            else if (*p == 'O') { changed = 1; *p = 'o'; }
        }
        if (changed) strcat(modified[cnt++], buffer);
    }

    if (cnt == 0)
        printf(fmts[N > 1], N, "and no account is modified\n");
    else {
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; ++i) {
            puts(modified[i]);
        }
    }
}
