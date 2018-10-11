#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const int MAXM = 1e5 + 5;
const int INF = 0x3F3F3F3F;
class Edge {
public:
    int to, cap, next;
}edge[MAXM << 1];
int n, m, cnt, St, Ed;
int h[MAXN], cur[MAXN], dis[MAXN];
int front, tail, que[MAXN];
bool vis[MAXN];
vector<int> path;
void addEdge(int u, int v, int w, int rw = 0) {
    edge[cnt].to = v;
    edge[cnt].cap = w;
    edge[cnt].next = h[u];
    h[u] = cnt++;
    swap(u, v);
    edge[cnt].to = v;
    edge[cnt].cap = rw;
    edge[cnt].next = h[u];
    h[u] = cnt++;
}
bool bfs(int s, int t) {
    int u, v;
    memset(dis, -1, sizeof dis);
    front = tail = 0;
    que[tail++] = s;
    dis[s] = 0;
    while (front < tail) {
        u = que[front++];
        for (int p = h[u]; ~p; p = edge[p].next) {
            v = edge[p].to;
            if (dis[v] == -1 && edge[p].cap) {
                dis[v] = dis[u] + 1;
                if (v == t) return true;
                que[tail++] = v;
            }
        }
    }
    return false;
}
int dfs(int u, int t, int cap) {
    if (u == t || cap == 0) return cap;
    int res = 0, flow;
    for (int &p = cur[u]; ~p; p = edge[p].next) {
        int v = edge[p].to;
        if (dis[v] == dis[u] + 1 && (flow = dfs(v, t, min(cap - res, edge[p].cap) > 0))) {
            edge[p].cap -= flow;
            edge[p ^ 1].cap += flow;
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
        memcpy(cur, h, sizeof h);
        ans += dfs(s, t, INF);
    }
    return ans;
}
void dfsPath(int u) {
    vis[u] = true;
    path.push_back(u);
    for (int p = h[u]; ~p; p = edge[p].next)
        if (edge[p].cap == 0) {
            int v = edge[p].to;
            if (v <= n || v == St || v == Ed) continue;
            v -= n;
            if (!vis[v]) dfsPath(v);
        }
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int u, v, i = 1; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v + n, 1);
    }
    St = (n << 1) + 1;
    Ed = (n << 1) + 2;
    for (int i = 1; i <= n; ++i) {
        addEdge(St, i, 1);
        addEdge(n + i, Ed, 1);
    }
    int ans = n - dinic(St, Ed);
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) {
            path.clear();
            dfsPath(i);
            for (int i = 0; i < (int)path.size(); ++i)
                printf(i == path.size() - 1 ? "%d\n" : "%d ", path[i]);
        }
    printf("%d\n", ans);
    return 0;
}