#include <bits/stdc++.h>
const int MAXN = 1e5 + 5;
const int MAXM = 105;
int top[MAXM], left[MAXN];
bool vis[MAXN][MAXM];
long long solve(int x, int y) {
    if (vis[x][y]) {
        top[y] = x;
        left[x] = y;
        return 0LL;
    }
    long long sum = 0;
    int mmin = INT_MAX;
    for (int j = y; j < left[x]; ++j) {
        mmin = std::min(mmin, top[j]);
        if (mmin <= x) break;
        sum += mmin - x;
    }
    return sum;
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T, n, m, k, tcas = 1;
    scanf("%d", &T);
    while (T--) {
        printf("Case #%d: ", tcas++);
        memset(vis, 0, sizeof vis);
        scanf("%d%d%d", &n, &m, &k);
        while (k--) {
            int x, y;
            scanf("%d%d", &x, &y);
            vis[x][y] = true;
        }
        for (int i = 1; i <= n; ++i)
            left[i] = m + 1;
        for (int i = 1; i <= m; ++i)
            top[i] = n + 1;
        long long ans = 0;
        for (int i = n; i; --i)
            for (int j = m; j; --j)
                ans += solve(i, j);
        printf("%lld\n", ans);
    }
    return 0;
}