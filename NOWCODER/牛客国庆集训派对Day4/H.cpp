#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int n, w[MAXN], depth[MAXN], cnt[MAXN];
vector<int> edge[MAXN];
void dfs(int u, int fa, int d) {
    depth[u] = d;
    for (int v : edge[u]) {
        if (v == fa) continue;
        dfs(v, u, d + 1);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &w[i]);
    for (int u, v, i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0, 1);
    for (int i = 1; i <= n; ++i)
        if (w[i]) ++cnt[depth[i]];
    for (int i = 1; i <= n; ++i)
        if (cnt[i] & 1) {
            puts("First");
            return 0;
        }
    puts("Second");
    return 0;
}