#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 100010;
const int MAXM = 100010;
const int INF = 0x3F3F3F3F;
class Edge {
public:
    int x, w, next;
}edge[MAXM << 1];
int n, m, cnt, S, T, MEMORY_SIZE;
int h[MAXN], cur[MAXN], dis[MAXN];
queue<int> Q;
void addEdge(int u, int v, int w) {
    edge[cnt].x = v;
    edge[cnt].w = w;
    edge[cnt].next = h[u];
    h[u] = cnt++;
}
bool bfs(int s, int t) {
    int u, v;
    memset(dis + 1, -1, MEMORY_SIZE);
    Q.push(s);
    dis[s] = 0;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (int p = h[u]; ~p; p = edge[p].next) {
            v = edge[p].x;
            if (dis[v] == -1 && edge[p].w) {
                dis[v] = dis[u] + 1;
                Q.push(v);
                if (v == t) break;
            }
        }
    }
    return dis[t] != -1;
}
int dfs(int u, int t, int cap) {
    if (u == t || cap == 0) return cap;
    int res = 0, flow;
    for (int &p = cur[u]; ~p; p = edge[p].next) {
        int v = edge[p].x;
        if (dis[v] == dis[u] + 1 && (flow = dfs(v, t, min(cap - res, edge[p].w))) > 0) {
            edge[p].w -= flow;
            edge[p ^ 1].w += flow;
            res += flow;
            if (res == cap) return cap;
        }
    }
    if (!res) dis[u] = -1;
    return res;
}
int dinic(int s, int t) {
    int ans = 0;
    while (bfs(s, t)) {
        memcpy(cur + 1, h + 1, MEMORY_SIZE);
        ans += dfs(s, t, INF);
    }
    return ans;
}
int main() {
    // freopen("in.txt", "r", stdin);
    int _;
    for (scanf("%d", &_); _; --_) {
        scanf("%d%d", &n, &m);
        int minx = INT_MAX, maxx = INT_MIN;
        for (int x, y, i = 1; i <= n; ++i) {
            scanf("%d%d", &x, &y);
            if (x < minx) {
                minx = x;
                S = i;
            }
            if (x > maxx) {
                maxx = x;
                T = i;
            }
        }
        MEMORY_SIZE = n * sizeof(int);
        cnt = 0;
        memset(h + 1, -1, MEMORY_SIZE);
        for (int u, v, w, i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        printf("%d\n", dinic(S, T));
    }
    return 0;
}