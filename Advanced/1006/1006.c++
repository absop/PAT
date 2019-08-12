#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct _person *pp;
typedef struct _person {
    string id;
    string intime;
    string outime;
} tp;

bool incmp(tp i, tp j) { return i.intime < j.intime; }
bool outcmp(tp i, tp j) { return i.outime < j.outime; }

int main()
{
    int M;
    cin >> M;
    vector<tp> v(M);
    for (int i = 0; i < M; ++i)
        cin >> v[i].id >> v[i].intime >> v[i].outime;

    tp unlock = *min_element(v.begin(), v.end(), incmp);
    tp lock = *max_element(v.begin(), v.end(), outcmp);
    cout << unlock.id << ' ' << lock.id << endl;
}
