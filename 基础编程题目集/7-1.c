#include<stdio.h>


int main()
{
  int cm, foot, inch;
  double m, t;
  scanf("%d", &cm);
  m = cm / 100.0;
  t = m / 0.3048;
  foot = (int)t;
  inch = (int)(12 * (t - foot));
  printf("%d %d\n", foot, inch);
  return 0;

}