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
vector<int> plan;
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
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &m, &n);
    St = (m << 1) + (n << 1) + 1;
    Ed = (m << 1) + (n << 1) + 2;
    int sr = 0;
    memset(h, -1, sizeof h);
    for (int r, i = 1; i <= m; ++i) {
        scanf("%d", &r);
        sr += r;
        addEdge(i, m + i, r);
        addEdge(St, i, INF);
    }
    for (int c, i = 1; i <= n; ++i) {
        scanf("%d", &c);
        addEdge((m << 1) + i, (m << 1) + n + i, c);
        addEdge((m << 1) + n + i, Ed, INF);
    }
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            addEdge(m + i, (m << 1) + j, 1);
    int ans = dinic(St, Ed);
    if (ans == sr) {
        puts("1");
        for (int i = 1; i <= m; ++i) {
            plan.clear();
            for (int p = h[m + i]; ~p; p = edge[p].next)
                if (edge[p].to >= (m << 1) && edge[p].to <= (m << 1) + n && edge[p].cap == 0)
                    plan.push_back(edge[p].to - (m << 1));
            sort(plan.begin(), plan.end());
            bool flag = false;
            for (int x : plan) {
                if (flag)
                    putchar(' ');
                else
                    flag = true;
                printf("%d", x);
            }
            putchar('\n');
        }
    }
    else
        puts("0");
    return 0;
}