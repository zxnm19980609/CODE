#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x7F7F7F7F;
const int MAXN = 100005;
const int MAXM = 200005;
class Edge {
public:
    int w, x, next;
}edge[MAXM];
int cnt, n, m, s, t, h[MAXN], dis[MAXN], indeg[MAXN];
queue<int> q, tps;
void addEdge(int u, int v, int w) {
    ++cnt;
    edge[cnt].x = v;
    edge[cnt].w = w;
    edge[cnt].next = h[u];
    h[u] = cnt;
    ++indeg[v];
}
void topoSort() {
    for (int i = 1; i <= n; ++i)
        if (indeg[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        tps.push(u);
        for (int p = h[u]; p; p = edge[p].next) {
            int v = edge[p].x;
            if (--indeg[v] == 0)
                q.push(v);
        }
    }
}
void solve() {
    dis[s] = 0;
    while (tps.front() != s) tps.pop();
    while (!tps.empty()) {
        int u = tps.front();
        tps.pop();
        if (dis[u] == INF) continue;
        for (int p = h[u]; p; p = edge[p].next) {
            int v = edge[p].x;
            dis[v] = min(dis[v], dis[u] + edge[p].w);
        }
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int u, v, w, i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
    }
    topoSort();
    memset(dis, 0x7F, sizeof dis);
    solve();
    if (dis[t] == INF)
        puts("Unreachable");
    else
        printf("%d\n", dis[t]);
    return 0;
}