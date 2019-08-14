#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct _person {
    string id;
    string intime;
    string outime;
} person;

bool cmp1(const person a, const person b) { return a.intime < b.intime; }
bool cmp2(const person a, const person b) { return a.outime < b.outime; }

int main()
{
    int M;
    cin >> M;
    vector<person> v(M);
    for (int i = 0; i < M; ++i)
        cin >> v[i].id >> v[i].intime >> v[i].outime;

    auto open = min_element(v.begin(), v.end(), cmp1);
    auto lock = max_element(v.begin(), v.end(), cmp2);
    cout << open->id << ' ' << lock->id << endl;
}
