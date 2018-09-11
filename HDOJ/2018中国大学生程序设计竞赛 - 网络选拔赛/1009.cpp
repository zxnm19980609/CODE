#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
class Edge {
public:
    int v, w, next;
}edge[MAXN << 1];
int n, cnt, h[MAXN];
LL ans, fac[MAXN];
void init() {
    fac[1] = 1;
    for (int i = 2; i < MAXN; ++i)
        fac[i] = fac[i - 1] * i % MOD;
}
void addEdge(int u, int v, int w) {
    ++cnt;
    edge[cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].next = h[u];
    h[u] = cnt;
}
int dfs(int u, int fa = -1) {
    int sum = 1;
    for (int p = h[u]; p; p = edge[p].next) {
        int v = edge[p].v;
        if (v == fa) continue;
        int t = dfs(v, u);
        sum += t;
        ans = (ans + (LL)t * (n - t) * edge[p].w) % MOD;
    }
    return sum;
}
int main() {
    // freopen("in.txt", "r", stdin);
    init();
    while (~scanf("%d", &n)) {
        cnt = 0;
        memset(h, 0, sizeof h);
        for (int u, v, w, i = 1; i < n; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        ans = 0;
        dfs(1);
        ans = ans * 2LL % MOD * fac[n - 1] % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
