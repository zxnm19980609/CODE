#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
const int MAXN = 505;
class KEdge {
public:
    PII u, v;
    LL w;
    KEdge() {}
    KEdge(PII u, PII v, LL w) : u(u), v(v), w(w) {}
    bool operator<(const KEdge &edge) const {
        return w > edge.w;
    }
};
int n, m, depth[MAXN][MAXN];
PII father[MAXN][MAXN], ancestor[MAXN][MAXN][25];
vector<KEdge> kedge;
vector<PII> edge[MAXN][MAXN];
PII find(PII x) {
    if (x.first == father[x.first][x.second].first &&
        x.second == father[x.first][x.second].second)
        return x;
    return father[x.first][x.second] = find(father[x.first][x.second]);
}
void kruskal() {
    sort(kedge.begin(), kedge.end());
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            father[i][j] = make_pair(i, j);
    for (auto &e : kedge) {
        PII fu = find(e.u);
        PII fv = find(e.v);
        if (fu != fv) {
            edge[e.u.first][e.u.second].push_back(e.v);
            edge[e.v.first][e.v.second].push_back(e.u);
            father[fv.first][fv.second] = fu;
        }
    }
}
void dfs(PII u, PII fa, int d) {
    depth[u.first][u.second] = d;
    ancestor[u.first][u.second][0] = fa;
    for (int i = 1; i < 25; ++i) {
        PII tmp = ancestor[u.first][u.second][i - 1];
        ancestor[u.first][u.second][i] = ancestor[tmp.first][tmp.second][i - 1];
    }
    for (auto &v : edge[u.first][u.second]) {
        if (v == fa) continue;
        dfs(v, u, d + 1);
    }
}
PII LCA(PII x, PII y) {
    if (depth[x.first][x.second] < depth[y.first][y.second])
        swap(x, y);
    for (int i = 24; ~i; --i)
         if (depth[x.first][x.second] - (1 << i) >= depth[y.first][y.second])
            x = ancestor[x.first][x.second][i];
    if (x == y) return x;
    for (int i = 24; ~i; --i)
        if (ancestor[x.first][x.second][i] != ancestor[y.first][y.second][i]) {
            x = ancestor[x.first][x.second][i];
            y = ancestor[y.first][y.second][i];
        }
    return ancestor[x.first][x.second][0];
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            char d, r;
            LL a, b;
            scanf(" %c %lld %c %lld ", &d, &a, &r, &b);
            if (d != 'X') {
                kedge.push_back(KEdge(PII(i, j), PII(i + 1, j), a));
                kedge.push_back(KEdge(PII(i + 1, j), PII(i, j), a));
            }
            if (r != 'X') {
                kedge.push_back(KEdge(PII(i, j), PII(i, j + 1), b));
                kedge.push_back(KEdge(PII(i, j + 1), PII(i, j), b));
            }
        }
    kruskal();
    dfs(PII(1, 1), PII(0, 0), 1);
    int q;
    scanf("%d", &q);
    while (q--) {
        PII x, y, lca;
        scanf("%d%d%d%d", &x.first, &x.second, &y.first, &y.second);
        lca = LCA(x, y);
        printf("%d\n", depth[x.first][x.second] + depth[y.first][y.second]
                       - 2 * depth[lca.first][lca.second]);
    }
    return 0;
}