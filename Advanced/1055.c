#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100001

typedef struct _one *pone;
typedef struct _one {
  char name[10];
  int age;
  int worth;
} tone;

int cntage[MAXN], record[MAXN], rcdnum;

static __inline int cmp(const void *a, const void *b)
{
  pone p = (struct _one *)a;
  pone q = (struct _one *)b;
  if (q->worth - p->worth)
    return q->worth - p->worth;
  else if (p->age - q->age)
    return p->age - q->age;
  else
    return strcmp(p->name, q->name);
}


int main()
{
  int N, K;

  scanf("%d %d", &N, &K);

  pone array = (pone)malloc(N * sizeof(tone));

  for (pone p = array; p < array + N; ++p)
    scanf("%s %d %d", p->name, &p->age, &p->worth);

  qsort(array, N, sizeof(struct _one), cmp);

  for (int i = 0; i < N; ++i) {
    if (cntage[array[i].age] <= 100) {
      cntage[array[i].age]++;
      record[rcdnum++] = i;
    }
  }

  int num, min, max, age, count;
  for (int i = 1; i <= K; ++i) {
    scanf("%d%d%d", &num, &min, &max);
    printf("Case #%d:\n", i);

    count = 0;
    for (int j = 0; j < rcdnum && count < num; ++j) {
      age = array[record[j]].age;
      if (min <= age && age <= max) {
        ++count;
        printf("%s %d %d\n", array[record[j]].name, array[record[j]].age,
               array[record[j]].worth);
      }
    }
    if (count == 0) printf("None\n");
  }

  free(array);
}
