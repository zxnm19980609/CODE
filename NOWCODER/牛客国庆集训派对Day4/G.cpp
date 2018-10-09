#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 3e5 + 5;
const int MOD = 1e9 + 7;
LL a[MAXN], w[MAXN];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &w[i]);
    int l = 1, r = n, m = n >> 1;
    LL tmp = 0, ans = 0;
    for (int i = 1; i <= m; ++i)
        w[i] += w[n - i + 1];
    for (int i = 1; i <= m; ++i) {
        tmp = (tmp + a[r] - a[l - 1]) % MOD;
        ans = (ans + w[i] * tmp % MOD) % MOD;
        ++l;
        --r;
    }
    if (n & 1) {
        tmp = (tmp + a[r] - a[l - 1]) % MOD;
        ans = (ans + w[m + 1] * tmp % MOD) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}