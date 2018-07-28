#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 1010;
const int MAXM = 100010;
const int INF = 0x3F3F3F3F;
class Edge {
public:
    int x, w, next;
}edge[MAXM << 1];
int n, cnt, N, F, D, S, T, MEMORY_SIZE;
int h[MAXN], cur[MAXN], dis[MAXN];
char str[210];
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
    while (~scanf("%d%d%d", &n, &F, &D)) {
        N = (n << 1) + F + D + 2;
        S = N - 1;
        T = N;
        MEMORY_SIZE = N * sizeof(int);
        cnt = 0;
        memset(h + 1, -1, MEMORY_SIZE);
        for (int w, i = 1; i <= F; ++i) {
            scanf("%d", &w);
            addEdge(S, (n << 1) + i, w);
            addEdge((n << 1) + i, S, 0);
        }
        for (int w, i = 1; i <= D; ++i) {
            scanf("%d", &w);
            addEdge((n << 1) + F + i, T, w);
            addEdge(T, (n << 1) + F + i, 0);
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%s", str + 1);
            for (int j = 1; j <= F; ++j)
                if (str[j] == 'Y') {
                    addEdge((n << 1) + j, i, INF);
                    addEdge(i, (n << 1) + j, 0);
                }
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%s", str + 1);
            for (int j = 1; j <= D; ++j)
                if (str[j] == 'Y') {
                    addEdge(n + i, (n << 1) + F + j, INF);
                    addEdge((n << 1) + F + j, n + i, 0);
                }
        }
        for (int i = 1; i <= n; ++i) {
            addEdge(i, n + i, 1);
            addEdge(n + i, i, 0);
        }
        printf("%d\n", dinic(S, T));
    }
    return 0;
}