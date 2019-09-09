#include <stdio.h>


struct _window {
    int q[1001];
    int head;
    int tail;
} windows[21] = {[0 ... 20] = {.tail = -1}};


#define head(w) windows[w].head
#define tail(w) windows[w].tail
#define vhead(w) windows[w].q[head(w)]
#define vtail(w) windows[w].q[tail(w)]
#define dequeue(w) ++head(w)
#define enqueue(w, e) windows[w].q[++tail(w)] = e


int main()
{
    int N, M, K, Q, idx;
    scanf("%d %d %d %d", &N, &M, &K, &Q);

    int done[K + 1], begin[K + 1];
    for (int i = 1; i <= K; ++i)
        scanf("%d", &done[i]);

    idx = 1;
    for (int w = 1; w <= N && idx <= K; ++w) {
        begin[idx] = 0;
        enqueue(w, done[idx++]);
    }
    for (int x = 2; x <= M; ++x)
        for (int w = 1; w <= N && idx <= K; ++w) {
            done[idx] += (begin[idx] = done[idx - N]);
            enqueue(w, done[idx++]);
        }

    while (idx <= K) {
        int mw = 1, leave = vhead(1);
        for (int i = 2; i <= N; ++i) {
            if (vhead(i) < leave) {
                mw = i;
                leave = vhead(i);
            }
        }
        // printf("%d号顾客排在第%d号窗口\n", idx, mw);
        dequeue(mw);
        done[idx] += (begin[idx] = vtail(mw));
        enqueue(mw, done[idx++]);
    }

    for (int i = 0; i < Q; ++i) {
        scanf("%d", &idx);
        if (begin[idx] >= 540)
            printf("Sorry\n");
        else {
            int minute = done[idx] + 480;
            printf("%02d:%02d\n", minute / 60, minute % 60);
        }
    }

    return 0;
}
