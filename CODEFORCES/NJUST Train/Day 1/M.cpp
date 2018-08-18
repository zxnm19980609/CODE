#include <cstdio>
using namespace std;
int n, m, s[110], d[110], c[110], b[110], ans[110];
bool exam[110];
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &s[i], &d[i], &c[i]);
        exam[d[i]] = true;
    }
    for (int i = 1; i <= n; ++i) {
        if (exam[i]) {
            ans[i] = m + 1;
            continue;
        }
        int p = -1, ddl = 110;
        for (int j = 1; j <= m; ++j)
            if (s[j] <= i && i < d[j] && b[j] < c[j] && d[j] < ddl) {
                p = j;
                ddl = d[j];
            }
        if (p == -1) {
            ans[i] = 0;
            continue;
        }
        ans[i] = p;
        ++b[p];
    }
    for (int i = 1; i <= n; ++i)
        if (b[i] != c[i]) {
            puts("-1");
            return 0;
        }
    for (int i = 1; i <= n; ++i)
        printf(i == n ? "%d\n" : "%d ", ans[i]);
    return 0;
}