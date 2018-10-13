#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
const int MAXE = 1e5 + 5;
const int INF = 0x3F3F3F3F;
class Edge {
public:
    int to, next, cap, flow, cost;
}edge[MAXE];
int n, P, M, F, N, S, need[MAXN];
int St, Ed, cnt;
int h[MAXN], pre[MAXN], dis[MAXN];
bool vis[MAXN];
void addEdge(int u, int v, int cap, int cost) {
    edge[cnt].to = v;
    edge[cnt].cap = cap;
    edge[cnt].cost = cost;
    edge[cnt].flow = 0;
    edge[cnt].next = h[u];
    h[u] = cnt++;
    edge[cnt].to = u;
    edge[cnt].cap = 0;
    edge[cnt].cost = -cost;
    edge[cnt].flow = 0;
    edge[cnt].next = h[v];
    h[v] = cnt++;
}
bool SPFA() {
    queue<int> Q;
    memset(dis, 0x3F, sizeof dis);
    memset(vis, 0, sizeof vis);
    memset(pre, -1, sizeof pre);
    dis[St] = 0;
    vis[St] = true;
    Q.push(St);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        vis[u] = false;
        for (int i = h[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            if (edge[i].cap > edge[i].flow && dis[v] > dis[u] + edge[i].cost) {
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i;
                if (!vis[v]) {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
    }
    return pre[Ed] != -1;
}
int MCMF(int &cost) {
    int flow = 0;
    cost = 0;
    while (SPFA()) {
        int Min = INF;
        for (int i = pre[Ed]; ~i; i = pre[edge[i ^ 1].to]) {
            if (Min > edge[i].cap - edge[i].flow)
                Min = edge[i].cap - edge[i].flow;
        }
        for (int i = pre[Ed]; ~i; i = pre[edge[i ^ 1].to]) {
            edge[i].flow += Min;
            edge[i ^ 1].flow -= Min;
            cost += edge[i].cost * Min;
        }
        flow += Min;
    }
    return flow;
}
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d%d%d%d%d", &n, &P, &M, &F, &N, &S);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &need[i]);
    St = (n << 1) + 1;
    Ed = (n << 1) + 2;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; ++i) {
        addEdge(St, i, INF, P);
        addEdge(n + i, Ed, INF, 0);
    }
    for (int i = 1; i <= n; ++i) {
        addEdge(i, n + i, need[i], 0);
        for (int j = i + M; j <= n && j < i + N; ++j)
            addEdge(n + i, j, INF, F);
        for (int j = i + N; j <= n; ++j)
            addEdge(n + i, j, INF, S);
    }
    int flow, cost;
    flow = MCMF(cost);
    printf("%d\n%d\n", flow, cost);
    return 0;
}