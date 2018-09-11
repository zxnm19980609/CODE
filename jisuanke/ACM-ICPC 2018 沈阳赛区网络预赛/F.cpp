#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
const int MAXM = 500005;
const int INF = 0x3F3F3F3F;
class Edge {
public:
    int x, w, next;
}edge[MAXM];
int cnt, n, m, k, l, r, S, SS, T, TT;
int h[MAXN], cur[MAXN], dis[MAXN];
queue<int> Q;
map<pair<int, int>, int> up;
void addEdge(int u, int v, int w) {
    edge[cnt].x = v;
    edge[cnt].w = w;
    edge[cnt].next = h[u];
    h[u] = cnt++;
    edge[cnt].x = u;
    edge[cnt].w = 0;
    edge[cnt].next = h[v];
    h[v] = cnt++;
}
bool bfs(int s, int t) {
    int u, v;
    memset(dis, -1, sizeof dis);
    while (!Q.empty()) Q.pop();
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
        memcpy(cur, h, sizeof h);
        ans += dfs(s, t, INF);
    }
    return ans;
}
int main() {
    // freopen("in.txt", "r", stdin);
    int tcas = 1;
    while (~scanf("%d%d%d", &n, &m, &k)) {
        printf("Case %d: ", tcas++);
        scanf("%d%d", &l, &r);
        up.clear();
        for (int u, v, i = 0; i < k; ++i) {
            scanf("%d%d", &u, &v);
            ++up[make_pair(u, v)];
        }
        S = (n << 1) + (m << 1) + 1;
        T = S + 1;
        SS = T + 1;
        TT = SS + 1;
        memset(h, -1, sizeof h);
        cnt = 0;
        for (int i = 1; i <= n; ++i) {
            addEdge(S, i, INF);
            addEdge(i, n + i, r - l);
        }
        for (int i = 1; i <= m; ++i) {
            addEdge((n << 1) + i, (n << 1) + m + i, r - l);
            addEdge((n << 1) + m + i, T, INF);
        }
        for (auto &p : up)
            addEdge(n + p.first.first, (n << 1) + p.first.second, p.second);
        addEdge(T, S, INF);
        for (int i = 1; i <= n; ++i) {
            addEdge(i, TT, l);
            addEdge(SS, n + i, l);
        }
        for (int i = 1; i <= m; ++i) {
            addEdge((n << 1) + i, TT, l);
            addEdge(SS, (n << 1) + m + i, l);
        }
        int maxflow = dinic(SS, TT);
        if (maxflow == (n + m) * l)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}