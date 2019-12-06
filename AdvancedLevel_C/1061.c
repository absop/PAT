#include <stdio.h>
#include <string.h>

char Day[7][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int toDay(char c) { return ('A' <= c && c <= 'G') ? c - 'A' : -1; }
int toHour(char c)
{
    return ('0' <= c && c <= '9') ? c - '0' :
           ('A' <= c && c <= 'N') ? c - 'A' + 10 :
           -1;
}
int toMinute(char c)
{
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

int main()
{
    int day, hour, minute;
    char lines[4][64], *p, *q;

    for (int i = 0; i < 4; ++i)
        scanf("%s", lines[i]);

    p = lines[0], q = lines[1];
    for (; *p && *q; ++p, ++q)
        if (*p == *q && (day = toDay(*p)) != -1)
            break;
    for (++p, ++q; *p && *q; ++p, ++q)
        if (*p == *q && (hour = toHour(*p)) != - 1)
            break;

    p = lines[2], q = lines[3];
    for (int i = 0; p[i] && q[i]; ++i)
        if (p[i] == q[i] && toMinute(p[i])) {
            minute = i;
            break;
        }

    printf("%s %02d:%02d", Day[day], hour, minute);

    return 0;
}
