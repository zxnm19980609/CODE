#include <bits/stdc++.h>
using namespace std;
const int MAX = 55;
const int INF = 0x3F3F3F3F;
class Edge {
public:
    int to, cap, next;
}edge[(MAX * MAX) << 2];
int n, m, St, Ed, expr[MAX], need[MAX][MAX];
int n, m, cnt, h[MAX << 1], cur[MAX << 1], dis[MAX << 1];
int front, tail, que[MAX << 1];
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
        memcpy(cur, h, sizeof cur);
        ans += dfs(s, t, INF);
    }
    return ans;
}
int main() {
    freopen("in.txt", "r", stdin);
    cin >> m >> n;
    string s;
    stringstream ss;
    for (int t, i = 1; i <= m; ++i) {
        cin >> s;
        ss << s;
        ss >> expr[i];
        while (ss >> t) {
            addEdge(i, m + t, INF);
            need[i][t] = true;
        }
    }
    St = n + m + 1;
    Ed = n + m + 2;
    dinic(St, Ed);
    return 0;
}