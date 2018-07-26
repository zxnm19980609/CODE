/**
 * 欧拉回路注意**联通子图**和**孤立点**
 */
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100010;
const int MAXM = 100010;
class {
public:
    int x, next, sign;
}edge[MAXM << 1];
int n, m, cnt, odc;
int h[MAXN], degree[MAXN], odd[MAXN];
void addEdge(int u, int v, int sign) {
    ++cnt;
    edge[cnt].x = v;
    edge[cnt].next = h[u];
    edge[cnt].sign = sign;
    h[u] = cnt;
}
void init() {
    cnt = 0;
    memset(h, 0, sizeof h);
    memset(degree, 0, sizeof degree);
    for (int u, v, i = 0; i < m; ++i) {
        scanf("%d%d", u, v);
        addEdge(u, v, 1);
        addEdge(v, u, -1);
        ++degree[u];
        ++degree[v];
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &n, &m)) {
        init();
        odc = 0;
        for (int i = 1; i <= n; ++i)
            if (degree[i] & 1) odd[odc++] = i;
        for (int i = 0; i < odc; i += 2) {
            addEdge(odd[i], odd[i + 1], 0);
            addEdge(odd[i + 1], odd[i], 0);
        }

    }
    return 0;
}