#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int MAXN = 100010;
const int MAXM = 100010;
class Edge{
public:
    int x, next, id, sign;
};
int n, m, p, cnt, odc;
int h[MAXN], degree[MAXN], odd[MAXN], viridx[MAXN];
bool visn[MAXN], vism[MAXM << 2];
stack<Edge> stk;
vector<int> ans[MAXN];
Edge edge[MAXM << 2], tmp[MAXN];
void addEdge(int u, int v, int id, int sign) {
    ++cnt;
    edge[cnt].x = v;
    edge[cnt].next = h[u];
    edge[cnt].id = id;
    edge[cnt].sign = sign;
    h[u] = cnt;
}
void dfs(int u) {
    visn[u] = true;
    for (int p = h[u]; p; p = edge[p].next)
        if (!vism[edge[p].id]) {
            vism[edge[p].id] = true;
            dfs(edge[p].x);
            stk.push(edge[p]);
        }
}
int main() {
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &n, &m)) {
        cnt = 0;
        memset(h, 0, sizeof h);
        memset(degree, 0, sizeof degree);
        for (int u, v, i = 1; i <= m; ++i) {
            scanf("%d%d", &u, &v);
            addEdge(u, v, i, 1);
            addEdge(v, u, i, -1);
            ++degree[u];
            ++degree[v];
        }
        odc = 0;
        for (int i = 1; i <= n; ++i)
            if (degree[i] & 1) odd[++odc] = i;
        for (int i = 1; i <= odc; i += 2) {
            addEdge(odd[i], odd[i + 1], m + i, 0);
            addEdge(odd[i + 1], odd[i], m + i, 0);
        }
        p = 0;
        memset(visn, 0, sizeof visn);
        memset(vism, 0, sizeof vism);
        for (int i = 1; i <= n; ++i)
            if (!visn[i]) {
                dfs(i);
                int c = 0;
                while (!stk.empty()) {
                    tmp[c++] = stk.top();
                    stk.pop();
                }
                if (!c) continue;
                int virc = 0;
                for (int j = 0; j < c; ++j)
                    if (!tmp[j].sign) viridx[virc++] = j;
                if (!virc) {
                    for (int j = 0; j < c; ++j)
                        ans[p].push_back(tmp[j].sign * tmp[j].id);
                    ++p;
                }
                else {
                    viridx[virc] = viridx[0];
                    for (int j = 0; j < virc; ++j) {
                        int k = (viridx[j] + 1) % c;
                        while (k != viridx[j + 1]) {
                            ans[p].push_back(tmp[k].sign * tmp[k].id);
                            k = (k + 1) % c;
                        }
                        if (ans[p].size()) ++p;
                    }
                }
            }
        printf("%d\n", p);
        for (int i = 0; i < p; ++i) {
            int sz = ans[i].size();
            printf("%d", (int)ans[i].size());
            for (int id : ans[i])
                printf(" %d", id);
            printf("\n");
            ans[i].clear();
        }
    }
    return 0;
}