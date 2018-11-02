#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
bool vis[MAXN];
int binarySearch(int s) {
    int l = 0, r = 1e5, m, ret = -1;
    while (l <= r) {
        m = (l + r) >> 1;
        if (1LL * m * (m + 1) / 2 <= 1LL * s) {
            ret = max(ret, m);
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return ret;
}
int main() {
    // freopen("in.txt", "r", stdin);
    int a, b;
    scanf("%d%d", &a, &b);
    int m = binarySearch(a + b);
    for (int i = m; i; --i)
        if (a >= i) {
            a -= i;
            vis[i] = true;
            if (a == 0) break;
        }
    a = 0;
    for (int i = 1; i <= m; ++i)
        if (vis[i]) ++a;
    printf("%d\n", a);
    for (int i = 1; i <= m; ++i)
        if (vis[i]) printf("%d ", i);
    putchar('\n');
    printf("%d\n", m - a);
    for (int i = 1; i <= m; ++i)
        if (!vis[i]) printf("%d ", i);
    putchar('\n');
    return 0;
}