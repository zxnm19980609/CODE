#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100005;
const int MAXM = 200005;
const LL INF = LLONG_MAX / 2;
namespace FastIO {
    inline char nc() {
        static char buf[100000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? '@' : *p1++;
    }
    int over;
    inline int nextInt() {
        char ch = nc();
        int s = 0;
        while(!(ch >= '0' && ch <= '9')) {
            ch = nc();
            if(ch == '@') { over = 1; break; }
        }
        while(ch >= '0' && ch <= '9') {
            s = s * 10 + ch - 48, ch = nc();
            if(ch == '@') { over = 1; break; }
        }
        return s;
    }
}
class QNode {
public:
    int mc, v;
    LL d;
    QNode() {}
    QNode(int mc, int v, LL d) : mc(mc), v(v), d(d) {}
    friend bool operator<(const QNode &a, const QNode &b) {
        return a.d > b.d;
    }
};
class Edge {
public:
    int v, w, next;
}edge[MAXM];
int n, m, k, cnt, h[MAXN];
LL dis[11][MAXN];
priority_queue<QNode> pq;
void addEdge(int u, int v, int w) {
    ++cnt;
    edge[cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].next = h[u];
    h[u] = cnt;
}
void dijkstra() {
    for (int i = 0; i <= k; ++i)
        for (int j = 1; j <= n; ++j)
            dis[i][j] = INF;
    while (!pq.empty()) pq.pop();
    pq.push(QNode(0, 1, 0));
    dis[0][1] = 0;
    while (!pq.empty()) {
        QNode now = pq.top();
        pq.pop();
        int mc = now.mc;
        int u = now.v;
        LL d = now.d;
        if (d != dis[mc][u]) continue;
        for (int p = h[u]; p; p = edge[p].next) {
            int v = edge[p].v;
            int w = edge[p].w;
            if (dis[mc][v] > dis[mc][u] + w) {
                dis[mc][v] = dis[mc][u] + w;
                pq.push(QNode(mc, v, dis[mc][v]));
            }
            if (mc < k && dis[mc + 1][v] > dis[mc][u]) {
                dis[mc + 1][v] = dis[mc][u];
                pq.push(QNode(mc + 1, v, dis[mc + 1][v]));
            }
        }
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    T = FastIO::nextInt();
    while (T--) {
        n = FastIO::nextInt();
        m = FastIO::nextInt();
        k = FastIO::nextInt();
        cnt = 0;
        for (int i = 1; i <= n; ++i)
            h[i] = 0;
        for (int u, v, w, i = 1; i <= m; ++i) {
            u = FastIO::nextInt();
            v = FastIO::nextInt();
            w = FastIO::nextInt();
            if (u == v) continue;
            addEdge(u, v, w);
        }
        dijkstra();
        LL ans = LLONG_MAX;
        for (int mc = 0; mc <= k; ++mc)
            ans = min(ans, dis[mc][n]);
        printf("%lld\n", ans);
    }
    return 0;
}