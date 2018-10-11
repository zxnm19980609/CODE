#include <bits/stdc++.h>
using namespace std;
const int N = 2e3;
const int MAXN = 5e3 + 5;
const int MAXM = 1e5 + 5;
const int INF = 0x3F3F3F3F;
class Edge {
public:
    int to, cap, next;
}edge[MAXM << 1];
int cnt, St, Ed;
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
bool check(int x) {
    int y = int(sqrt(x) + 0.5);
    if (y * y == x) return true;
    return false;
}
void dfsPath(int u) {
    vis[u] = true;
    path.push_back(u);
    for (int p = h[u]; ~p; p = edge[p].next)
        if (edge[p].cap == 0) {
            int v = edge[p].to;
            if (v <= N || v == St || v == Ed) continue;
            v -= N;
            if (!vis[v]) dfsPath(v);
        }
}
int main() {
    memset(h, -1, sizeof h);
    int lim, sum = 0, num = 0;
    scanf("%d", &lim);
    St = MAXN - 6;
    Ed = MAXN - 5;
    while (num - sum <= lim) {
        ++num;
        for (int i = 1; i < num; ++i)
            if (check(i + num)) addEdge(i, N + num, 1);
        addEdge(St, num, 1);
        addEdge(N + num, Ed, 1);
        sum += dinic(St, Ed);
    }
    --num;
    printf("%d\n", num);
    for (int i = 1; i <= num; ++i)
        if (!vis[i]) {
            path.clear();
            dfsPath(i);
            for (int i = 0; i < (int)path.size(); ++i)
                printf(i == path.size() - 1 ? "%d\n" : "%d ", path[i]);
        }
    return 0;
}