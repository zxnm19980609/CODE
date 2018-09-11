#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
LL dp[505][505];
int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            for (int p = 1; p <= j; ++p)
                dp[i][j] = (dp[i][j] + dp[i - p][min(i - p, j)]) % MOD;
    ans
    for (int )
    return 0;
}