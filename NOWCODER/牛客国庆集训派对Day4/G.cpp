#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 3e5 + 5;
const int MOD = 1e9 + 7;
LL a[MAXN], w[MAXN];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &w[i]);
        w[i] = (w[i] + w[i - 1]) % MOD;
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = (ans + a[i] * (w[n - i + 1] + w[i] - w[1]) % MOD) % MOD;
    printf("%lld\n", ans);
    return 0;
}