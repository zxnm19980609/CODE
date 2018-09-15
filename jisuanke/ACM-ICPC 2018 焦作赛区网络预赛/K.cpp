#include <bits/stdc++.h>
using namespace std;
const int MAXS = 1e4;
const int MAXM = 2e5 + 5;
const int MOD = 1e9 + 7;
int n, m, v[MAXM], sv[25], sc[25];
int dp[MAXS + 5];
int main() {
    int T, q, s;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &sv[i], &sc[i]);
        int m = 0;
        for (int i = 1; i <= n; ++i)
            for (int t, j = 0; j < sc[i]; ++j) {
                t = 1 << j;
                if (t > MAXS) break;
                v[++m] = t * sv[i];
            }
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (int i = 1; i <= m; ++i)
            for (int j = MAXS; j >= v[i]; --j)
                dp[j] = (dp[j] + dp[j - v[i]]) % MOD;
        while (q--) {
            scanf("%d", &s);
            printf("%d\n", dp[s]);
        }
    }
    return 0;
}