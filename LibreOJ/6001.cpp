

#include <bits/stdc++.h>
using namespace std;
const int MAX = 55;
const int INF = 0x3F3F3F3F;
class Edge {
public:
    int to, cap, next;
}edge[(MAX * MAX) << 2];
int n, m, St, Ed, expr[MAX], inst[MAX], need[MAX][MAX];
int cnt, h[MAX << 1], cur[MAX << 1], dis[MAX << 1];
int front, tail, que[MAX << 1];
bool selectE[MAX], selectI[MAX];
char s[10005];
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
void print(int ans) {
    for (int i = 1; i <= m; ++i)
        if (~dis[i]) selectE[i] = true;
    for (int i = 1; i <= m; ++i)
        if (selectE[i]) {
            for (int j = 1; j <= n; ++j)
                if (need[i][j])
                    selectI[j] = true;
        }
    bool flag = false;
    for (int i = 1; i <= m; ++i)
        if (selectE[i]) {
            if (flag)
                putchar(' ');
            else
                flag = true;
            printf("%d", i);
        }
    putchar('\n');
    flag = false;
    for (int i = 1; i <= n; ++i)
        if (selectI[i]) {
            if (flag)
                putchar(' ');
            else
                flag = true;
            printf("%d", i);
        }
    putchar('\n');
    printf("%d\n", ans);
}
int main() {
    scanf(" %d %d ", &m, &n);
    memset(h, -1, sizeof h);
    for (int t, i = 1; i <= m; ++i) {
        gets(s);
        stringstream ss;
        ss << s;
        ss >> expr[i];
        while (ss >> t) {
            addEdge(i, m + t, INF);
            need[i][t] = true;
        }
    }
    for (int i = 1; i <= n; ++i)
        cin >> inst[i];
    St = n + m + 1;
    Ed = n + m + 2;
    for (int i = 1; i <= m; ++i)
        addEdge(St, i, expr[i]);
    for (int i = 1; i <= n; ++i)
        addEdge(m + i, Ed, inst[i]);
    int ans = -dinic(St, Ed);
    for (int i = 1; i <= m; ++i)
       ans += expr[i];
    print(ans);
    return 0;
}
