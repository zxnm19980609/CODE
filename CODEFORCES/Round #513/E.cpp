#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 2e5 + 5;
vector<int> edge[MAXN];
int n;
LL ans, sz[MAXN], cnt[2];
void dfs(int u, int fa, int k) {
    sz[u] = 1;
    ++cnt[k];
    for (int v : edge[u]) {
        if (v == fa) continue;
        dfs(v, u, k ^ 1);
        sz[u] += sz[v];
    }
}
int main() {
    scanf("%d", &n);
    for (int u, v, i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; ++i)
        ans += sz[i] * (n - sz[i]);
     ans += cnt[0] * cnt[1];
    ans >>= 1;
    printf("%lld\n", ans);
    return 0;
}