#include <stdio.h>

//////////////////////////////
// 100f + y - n = 200y + 2f //
// 199y = 98f - n           //
// y = (98f - n)/199        //
// f < 100                  //
//////////////////////////////

int main()
{
    int y, n, f = 0;
    scanf("%d", &n);

    for (int i = 1; i < 100; ++i) {
        int r = (98 * i - n);
        y = r / 199;
        if ( y * 199 == r) {
            f = i;
            break;
        }
    }
    if (f) printf("%d.%d\n", y, f);
    else   printf("No Solution\n");
}
