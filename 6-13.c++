#include <iostream>
using namespace std;

#define MAXSIZE 50
typedef int KeyType;

typedef struct {
  KeyType key;
} ElemType;

typedef struct {
  ElemType *R;
  int length;
} SSTable;

void Create(SSTable &T) {
  int i;
  T.R = new ElemType[MAXSIZE + 1];
  cin >> T.length;
  for (i = 1; i <= T.length; i++) cin >> T.R[i].key;
}

int Search_Bin(SSTable T, KeyType k);

int main() {
  SSTable T;
  KeyType k;
  Create(T);
  cin >> k;
  int pos = Search_Bin(T, k);
  if (pos == 0)
    cout << "NOT FOUND" << endl;
  else
    cout << pos << endl;
  return 0;
}

int Search_Bin(SSTable T, KeyType k) {
  int lo = 1, mi, hi = T.length;
  while (lo <= hi) {
    mi = (lo + hi) >> 1;

    if (k == T.R[mi].key) return mi;
    if (k < T.R[mi].key)
      hi = mi - 1;
    else
      lo = mi + 1;
  }
  return 0;
}
