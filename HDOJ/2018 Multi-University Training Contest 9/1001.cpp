#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, m, MOD, dp[81][81][80 * 80 + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld", &n, &m, &MOD);
        memset(dp, 0, sizeof dp);
        dp[1][1][1] = n * m % MOD;
        for (LL i = 1; i <= n; ++i) {
            for (LL j = (i == 1 ? 2 : 1); j <= m; ++j) {
                for (LL k = i + j - 1; k <= i * j; ++k) {
                    dp[i][j][k] = ((dp[i][j][k - 1] * (i * j - k + 1) % MOD) +
                                   (dp[i - 1][j][k - 1] * (n - i + 1) % MOD * j % MOD) +
                                   (dp[i][j - 1][k - 1] * (m - j + 1) % MOD * i % MOD)) % MOD;
                }
            }
        }
        printf("%lld\n", dp[n][m][n * m] % MOD);
    }
    return 0;
}