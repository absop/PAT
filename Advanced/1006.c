#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _person {
    char ident[16];
    char itime[16];
    char otime[16];
} person_t;

int main()
{
    int M;
    person_t *v, *p, *open, *lock;

    scanf("%d", &M);
    open = lock = v = (person_t *)malloc(sizeof(person_t) * M);
    for (p = v; p < v + M; ++p)
        scanf("%s %s %s", p->ident, p->itime, p->otime);
    for (p = v + 1; p < v + M; ++p) {
        if (strcmp(p->itime, open->itime) < 0) open = p;
        if (strcmp(p->otime, lock->otime) > 0) lock = p;
    }
    printf("%s %s\n", open->ident, lock->ident);

    free(v);
}
