#include <stdio.h>
#include <stdlib.h>

typedef struct people {
    int id, virtue, talent;
} people_t;

typedef struct vector {
    int length, allocated;
    people_t *data;
} vector_t;

vector_t people[4];

int cmp(const void *a, const void *b)
{
    people_t *pa = (people_t *)a, *pb = (people_t *)b;
    int virtue = pb->virtue - pa->virtue;
    int remain = pb->talent - pa->talent + virtue;
    if (remain) return remain;
    if (virtue) return virtue;
    return pa->id - pb->id;
}

void append(vector_t *v, int id, int virtue, int talent)
{
    if (v->length >= v->allocated) {
        v->allocated += 5;
        v->data = (people_t *)realloc(
                      v->data, v->allocated * sizeof (people_t));
    }
    v->data[v->length++] = (people_t) { id, virtue, talent };
}

int main()
{
    int N, L, H, id, virtue, talent, class;
    scanf("%d %d %d", &N, &L, &H);

    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d", &id, &virtue, &talent);
        if (virtue >= L && talent >= L) {
            if (virtue >= H && talent >= H) {
                class = 0;  /* sage */
            }
            else if (virtue >= H)
                class = 1;  /* nobleman */
            else if (talent < H && virtue >= talent)
                class = 2;  /* fool man */
            else
                class = 3;  /* small man */

            append(&people[class], id, virtue, talent);
        }
    }

    int ranked = 0;
    for (int i = 0; i < 4; ++i)
        ranked += people[i].length;
    printf("%d\n", ranked);

    for (int i = 0; i < 4; ++i) {
        people_t *v = people[i].data;
        qsort(v, people[i].length, sizeof v[0], cmp);
        for (int j = 0; j < people[i].length; ++j)
            printf("%d %d %d\n", v[j].id, v[j].virtue, v[j].talent);
    }

    for (int i = 0; i < 4; ++i)
        free(people[i].data);

    return 0;
}
