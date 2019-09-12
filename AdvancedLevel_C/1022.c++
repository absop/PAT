#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<string, vector<int>> maps[5];

void query(int ith, string str)
{
    if (maps[ith].find(str) != maps[ith].end()) {
        sort(maps[ith][str].begin(), maps[ith][str].end());
        for (int i : maps[ith][str])
            printf("%07d\n", i);
    }
    else
        printf("Not Found\n");
}

int main()
{
    int n, m, id, ith;
    char keys[5][96];
    string key;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d\n", &id);
        for (int j = 0; j < 5; ++j) {
            cin.getline(keys[j], 96);
            if (j != 2){
                key = string(keys[j]);
                maps[j][key].push_back(id);
            }
        }
        for (char *p = keys[2], *q = p; *p; ++q) {
            if (*q == ' ' || *q == 0) {
                key = string(p, q);
                maps[2][key].push_back(id);
                p = q + (*q == ' ');
            }
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d: ", &ith);
        getline(cin, key);
        printf("%d: %s\n", ith, key.c_str());
        query(ith - 1, key);
    }
    return 0;
}
