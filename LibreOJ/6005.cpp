#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const int MAXM = 1e5 + 5;
const int INF = 0x3F3F3F3F;
class Edge {
public:
    int to, cap, next;
}edge[MAXM << 1];
int n, a[MAXN], b[MAXN], dp[MAXN];
int cnt, St, Ed;
int h[MAXN], cur[MAXN], dis[MAXN];
int front, tail, que[MAXN];
void LIS() {
    int pos, len = 1;
    b[1] = a[1];
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] >= b[len]) {
            b[++len] = a[i];
            dp[i] = len;
        }
        else {
            pos = lower_bound(b + 1, b + len + 1, a[i]) - b;
            b[pos] = a[i];
            dp[i] = pos;
        }

    }
}
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
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n ; ++i)
        scanf("%d", &a[i]);
    LIS();
    printf("%d\n", dp[n]);
    St = (n << 1) + 1;
    Ed = (n << 1) + 2;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; ++i) {
        addEdge(St, i, INF);
        addEdge(n + i, Ed, INF);
    }
    puts("===");
    for (int i = 1; i <= n; ++i)
        printf("%d ", dp[i]);

    puts("\n===");
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (dp[j] == dp[i] + 1)
                addEdge(i, n + j, 1);
    printf("%d\n", dinic(St, Ed));

    return 0;
}