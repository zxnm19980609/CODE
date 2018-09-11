#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
class Node {
public:
    set<int> *divisors;
    int size() {
        return divisors->size();
    }
    void clear() {
        divisors->clear();
    }
    set<int>::iterator find(int x) {
        return divisors->find(x);
    }
    set<int>::iterator begin() {
        return divisors->begin();
    }
    set<int>::iterator end() {
        return divisors->end();
    }
    void insert(int x) {
        divisors->insert(x);
    }
}d[MAXN];
class Edge {
public:
    int to, next;
}edge[MAXN << 1];
int n, cnt, h[MAXN], ans[MAXN];
vector<int> f[MAXN];
void init() {
    for (int i = 1; i < MAXN; ++i)
        for (int j = i; j < MAXN; j += i)
            f[j].push_back(i);
}
void addEdge(int u, int v) {
    ++cnt;
    edge[cnt].to = v;
    edge[cnt].next = h[u];
    h[u] = cnt;
}
Node merge(int u, int v) {
    if (d[u].size() < d[v].size())
        swap(d[u], d[v]);
    for (auto& x : *(d[v].divisors))
        if (d[u].find(x) == d[u].end())
            d[u].insert(x);
        else
            ans[u] = max(ans[u], x);
    d[v].clear();
    return d[u];
}
void dfs(int u, int fa = -1) {
    for (int p = h[u]; p; p = edge[p].next) {
        int v = edge[p].to;
        if (v == fa) continue;
        dfs(v, u);
        d[u] = merge(u, v);
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    init();
    scanf("%d", &n);
    for (int v, u = 2; u <= n; ++u) {
        scanf("%d", &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    for (int val, i = 1; i <= n; ++i) {
        scanf("%d", &val);
        d[i].divisors = new set<int>;
        for (auto& x : f[val])
            d[i].insert(x);
    }
    memset(ans, -1, sizeof ans);
    dfs(1);
    for (int i = 1; i <= n; ++i)
        printf("%d\n", ans[i]);
    return 0;
}