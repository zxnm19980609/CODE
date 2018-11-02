#include <bits/stdc++.h>
using namespace std;
const int MAXS = (1 << 21) + 5;
const int MAXM = 1e7 + 5;
class Edge {
public:
    int to, cost, next;
}edge[MAXM << 1];
int n, m, St, Ed, cnt, f1, f2, t;
int h[MAXS], dis[MAXS];
bool vis[MAXS];
char s1[25], s2[25];
queue<int> que;
void addEdge(int u, int v, int w) {
    ++cnt;
    edge[cnt].to = v;
    edge[cnt].cost = w;
    edge[cnt].next = h[u];
    h[u] = cnt;
}
void dfs(int pos, int state) {
    if (pos < 0) {
        int u = state;
        int v = (state & f1) | f2;
        if (u != v) addEdge(u, v, t);
        return;
    }
    if (s1[pos] == '+')
        dfs(pos - 1, state << 1 | 1);
    else if (s1[pos] == '-')
        dfs(pos - 1, state << 1);
    else {
        dfs(pos - 1, state << 1);
        dfs(pos - 1, state << 1 | 1);
    }
}
void SPFA(int s, int t) {
    memset(dis, 0x3F, sizeof dis);
    que.push(s);
    dis[s] = 0;
    vis[s] = true;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for (int p = h[u]; p; p = edge[p].next) {
            int v = edge[p].to;
            if (dis[v] > dis[u] + edge[p].cost) {
                dis[v] = dis[u] + edge[p].cost;
                if (!vis[v]) {
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    St = (1 << n) - 1;
    Ed = 0;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%s%s", &t, s1, s2);
        f1 = f2 = 0;
        for (int i = 0; i < n; ++i)
            f1 = f1 << 1 | 1;
        for (int i = 0; i < n; ++i)
            if (s2[i] == '-')
                f1 ^= (1 << i);
            else if (s2[i] == '+')
                f2 |= (1 << i);
        dfs(n - 1, 0);
    }
    SPFA(St, Ed);
    if (dis[Ed] == 0x3F3F3F3F) dis[Ed] = 0;
    printf("%d\n", dis[Ed]);
    return 0;
}