#include <bits/stdc++.h>
using namespace std;
const int MAXM = 205;
const int MAXN = 100005;
const int MAXE = 1000005;
const int INF = 0x3F3F3F3F;
class Video {
public:
    int startTime, endTime, w, op;
}videos[MAXM];
class Edge {
public:
    int to, next, cap, flow, cost;
}edge[MAXE];
int MEMORY_SIZE, St, Ed, cnt;
int n, m, N, K, W;
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
    memset(dis, 0x3F, MEMORY_SIZE);
    memset(vis, 0, MEMORY_SIZE);
    memset(pre, -1, MEMORY_SIZE);
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
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &n, &m, &K, &W);
        for (int i = 1; i <= m; ++i)
            scanf("%d%d%d%d", &videos[i].startTime, &videos[i].endTime, &videos[i].w, &videos[i].op);
        N = 1 + K + m * 2 + 1;
        MEMORY_SIZE = N * sizeof(int);
        memset(h, -1, MEMORY_SIZE);
        St = 0;
        Ed = N - 1;
        cnt = 0;
        for (int i = 1; i <= K; ++i)
            addEdge(St, i, 1, 0);
        for (int i = 1; i <= K; ++i)
            for (int j = 1; j <= m; ++j)
                addEdge(i, K + j, 1, 0);
        for (int i = 1; i <= m; ++i)
            addEdge(K + i, K + m + i, 1, -videos[i].w);
        for (int i = 1; i <= m; ++i)
            addEdge(K + m + i, Ed, 1, 0);
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= m; ++j)
                if (videos[j].startTime >= videos[i].endTime) {
                    int cost;
                    if (videos[i].op != videos[j].op)
                        cost = 0;
                    else
                        cost = W;
                    addEdge(K + m + i, K + j, 1, cost);
                }
        int ans;
        MCMF(ans);
        printf("%d\n", -ans);
    }
    return 0;
}