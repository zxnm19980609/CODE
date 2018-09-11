#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 25;
const int MAXS = (1 << 21) + 5;
int n, a[MAXN], b[MAXN], s[MAXN], pre[MAXN];
LL dp[MAXS];
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &a[i], &b[i], &s[i]);
        for (int p, j = 0; j < s[i]; ++j) {
            scanf("%d", &p);
            pre[i] |= 1 << (p - 1);
        }
    }
    for (int i = 0; i < MAXS; ++i)
        dp[i] = LLONG_MIN;
    dp[0] = 0;
    for (int i = 1; i < (1 << n); ++i)
        for (int j = 0; j < n; ++j)
            if ((i & (1 << j)) &&
                (!pre[j] || (((i ^ (1 << j)) & pre[j]) == pre[j])))
                    dp[i] = max(dp[i], dp[i ^ (1 << j)] + (LL)a[j] * __builtin_popcount(i) + b[j]);
    LL ans = LLONG_MIN;
    for (int i = 0; i < (1 << n); ++i)
        ans = max(ans, dp[i]);
    printf("%lld\n", ans);
    return 0;
}