#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, k;
LL dp[MAXN][3];
LL quickPow(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
int main() {
    int T, n, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        LL w = quickPow(2, k);
        if (n == 1) {
            printf("%lld\n", w);
            continue;
        }
        dp[2][0] = w * (w - 2 + MOD) % MOD;
        dp[2][1] = w;
        dp[2][2] = 0;
        for (int i = 3; i <= n; ++i) {
            dp[i][0] = (dp[i - 1][0] * (w - 3 + MOD) % MOD +
                        dp[i - 1][1] * (w - 2 + MOD) % MOD +
                        dp[i - 1][2] * (w - 2 + MOD) % MOD ) % MOD;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        }
        printf("%lld\n", (dp[n][0] + dp[n][1]) % MOD);
    }
    return 0;
}