#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int n, c, ct, a[MAXN], b[MAXN], t[MAXN], vis[MAXN];
vector<int> edge[MAXN], v[MAXN];
void dfs(int u, int fa) {
    if (vis[u]) {
        puts("-1");
        exit(0);
    }
    vis[u] = c;
    for (int v : edge[u])
        if (v != fa) dfs(v, u);
}
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a[i], &b[i]);

    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) {
            ++c;
            dfs(i, -1);
        }
    for (int i = 1; i <= n; ++i)
        v[vis[i]].push_back()
    return 0;
}