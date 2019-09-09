#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _person {
    char name[10];
    int age;
    int worth;
} person_t;

#define MAXN 100001
#define cvptr const void *
int cntage[MAXN], record[MAXN], rcdnum;
int cmp(cvptr a, cvptr b)
{
    person_t *p = (person_t *)a, *q = (person_t *)b;
    return q->worth != p->worth ? q->worth - p->worth
           : p->age != q->age ? p->age - q->age
           : strcmp(p->name, q->name);
}

int main()
{
    int N, K, num, min, max, age, count;

    scanf("%d %d", &N, &K);

    person_t *v = (person_t *)malloc(N * sizeof(person_t));
    for (person_t *p = v; p < v + N; ++p)
        scanf("%s %d %d", p->name, &p->age, &p->worth);

    qsort(v, N, sizeof(person_t), cmp);

    for (int i = 0; i < N; ++i) {
        if (cntage[v[i].age] <= 100) {
            cntage[v[i].age]++;
            record[rcdnum++] = i;
        }
    }
    for (int i = 1; i <= K; ++i) {
        scanf("%d%d%d", &num, &min, &max);
        printf("Case #%d:\n", i);
        count = 0;
        for (int j = 0; j < rcdnum && count < num; ++j) {
            age = v[record[j]].age;
            if (min <= age && age <= max) {
                ++count;
                printf("%s %d %d\n", v[record[j]].name, v[record[j]].age,
                       v[record[j]].worth);
            }
        }
        if (count == 0) printf("None\n");
    }
    free(v);

    return 0;
}
