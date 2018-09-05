#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXM = 400005;
class Edge {
public:
    int to, next, type;
}edge[MAXM];
int n, m, cnt, h[MAXN], dis[MAXN];
bool vis[MAXN];
set<int> last[MAXN];
queue<int> q;
void addEdge(int u, int v, int c) {
    ++cnt;
    edge[cnt].to = v;
    edge[cnt].type = c;
    edge[cnt].next = h[u];
    h[u] = cnt;
}
int spfa() {
    for (int i = 1; i <= n; ++i)
        last[i].clear();
    memset(dis, 0x3F, sizeof dis);
    memset(vis, 0, sizeof vis);
    while (!q.empty()) q.pop();
    dis[1] = 0;
    vis[1] = true;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int p = h[u]; p; p = edge[p].next) {
            int v = edge[p].to;
            int w = last[u].find(edge[p].type) == last[u].end() ? 1 : 0;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                last[v].clear();
                last[v].insert(edge[p].type);
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
            else if (dis[v] == dis[u] + w && w == 1) {
                last[v].insert(edge[p].type);
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return dis[n] == 0x3F3F3F3F ? -1 : dis[n];
}
int main() {
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &n, &m)) {
        cnt = 0;
        memset(h, 0, sizeof h);
        for (int u, v, c, i = 1; i <= m; ++i) {
            scanf("%d%d%d", &u, &v, &c);
            addEdge(u, v, c);
            addEdge(v, u, c);
        }
        printf("%d\n", spfa());
    }
    return 0;
}