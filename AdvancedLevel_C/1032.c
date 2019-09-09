#include <stdio.h>
#include <stdbool.h>

struct _node {
    int next: 24;
    bool visit;
} map[100000];


int main()
{
    int word1, word2, N;
    int addr, c, next;
    scanf("%d %d %d", &word1, &word2, &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %c %d", &addr, &c, &next);
        map[addr].next = next;
    }

    for (addr = word1; addr != -1; addr = map[addr].next)
        map[addr].visit = true;
    for (addr = word2; addr != -1 && !map[addr].visit; addr = map[addr].next);

    printf(addr == -1 ? "%d\n" : "%05d\n", addr);
}
