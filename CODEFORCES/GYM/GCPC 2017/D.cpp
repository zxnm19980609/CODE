#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
char s1[50], s2[50];
string nyt[205][2], donald[205][2];
map<string, int> idx;
vector<int> edge[205];
queue<int> q;
bool bfs(int s, int t) {
    if (s == t) return false;
    while (!q.empty()) q.pop();
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v : edge[u]) {
            if (v == t) return true;
            q.push(v);
        }
    }
    return false;
}
int check(int s, int t) {
    if (bfs(s, t))
        return 1;
    else if (bfs(t, s))
        return 0;
    else
        return 2;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf(" %s are worse than %s ", s1, s2);
        nyt[i][0] = s1;
        nyt[i][1] = s2;
        if (idx.find(nyt[i][0]) == idx.end())
            idx.insert(make_pair(nyt[i][0], ++cnt));
        if (idx.find(nyt[i][1]) == idx.end())
            idx.insert(make_pair(nyt[i][1], ++cnt));
    }
    for (int i = 1; i <= n; ++i)
        edge[idx[nyt[i][0]]].push_back(idx[nyt[i][1]]);
    for (int i = 1; i <= m; ++i) {
        scanf(" %s are worse than %s ", s1, s2);
        donald[i][0] = s1;
        donald[i][1] = s2;
        if (idx.find(donald[i][0]) == idx.end())
            idx.insert(make_pair(donald[i][0], ++cnt));
        if (idx.find(donald[i][1]) == idx.end())
            idx.insert(make_pair(donald[i][1], ++cnt));
    }
    for (int i = 1; i <= m; ++i) {
        int f = check(idx[donald[i][0]], idx[donald[i][1]]);
        if (f == 0)
            puts("Alternative Fact");
        else if (f == 1)
            puts("Fact");
        else if (f == 2)
            puts("Pants on Fire");
    }
    return 0;
}