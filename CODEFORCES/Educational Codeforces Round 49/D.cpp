#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, c[MAXN], ans[MAXN], edge[MAXN];
int timestamp, color, dfn[MAXN], low[MAXN], belong[MAXN];
bool vis[MAXN];
stack<int> s;
void tarjan(int u) {
    int v;
    dfn[u] = low[u] = ++timestamp;
    s.push(u);
    vis[u] = true;
    v = edge[u];
    if (!dfn[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
    }
    else if (vis[v])
        low[u] = min(low[u], dfn[v]);
    if (low[u] == dfn[u]) {
        ++color;
        do {
            v = s.top();
            s.pop();
            vis[v] = false;
            belong[v] = color;
        } while (u != v);
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);
    for (int t, i = 1; i <= n; ++i) {
        scanf("%d", &t);
        edge[i] = t;
    }
    for (int i = 1; i <= n; ++i)
        if (!dfn[i]) tarjan(i);
    memset(ans, 0x3F, sizeof ans);
    for (int i = 1; i <= n; ++i)
        if (belong[i] == belong[edge[i]])
            ans[belong[i]] = min(ans[belong[i]], c[i]);
    long long sum = 0LL;
    for (int i = 1; i <= color; ++i)
        if (ans[i] != 0x3F3F3F3F)
            sum += ans[i];
    printf("%I64d\n", sum);
    return 0;
}