#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 2e5 + 10;
int n, m, father[MAX], degree[MAX];
bool cir[MAX];
int unionFind(int x) {
    if (x == father[x]) return x;
    father[x] = unionFind(father[x]);
    return father[x];
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        father[i] = i;
    for (int u, v, i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        ++degree[u];
        ++degree[v];
        int fu = unionFind(u);
        int fv = unionFind(v);
        father[fv] = fu;
    }
    memset(cir, 1, sizeof cir);
    for (int i = 1; i <= n; ++i)
        if (degree[i] != 2) cir[unionFind(i)] = false;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (father[i] == i && cir[i])
            ++ans;
    printf("%d\n", ans);
    return 0;
}