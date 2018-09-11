#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 300005;
const LL INF = LLONG_MAX >> 3;
LL a[MAXN][7];
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        ++k;
        for (int i = 1; i <= n; ++i) {
            a[i][0] = INF;
            for (int j = 1; j <= k; ++j)
                scanf("%lld", &a[i][j]);
        }
        for (int i = 1; i <= m; ++i) {
            a[n + i][0] = -INF;
            for (int j = 1; j <= k; ++j)
                scanf("%lld", &a[n + i][j]);
            a[n + i][1] = -a[n + i][1];
        }
        ++k;
        n += m;
        LL mmin, mmax, t, ans = 0;
        for (int s = 0; s < (1 << k); ++s) {
            mmin = LLONG_MAX, mmax = LLONG_MIN;
            for (int i = 1; i <= n; ++i) {
                t = 0;
                for (int j = 0; j < k; ++j)
                    if ((1 << j) & s)
                        t += a[i][j];
                    else
                        t -= a[i][j];
                mmin = min(mmin, t);
                mmax = max(mmax, t);
            }
            ans = max(ans, mmax - mmin);
        }
        printf("%lld\n", ans - (INF << 1));
    }
    return 0;
}