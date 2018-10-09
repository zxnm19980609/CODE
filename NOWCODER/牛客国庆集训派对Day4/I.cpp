#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 1e5 + 5;
const int MOD = 998244353;
LL n, ans, a[MAXN];
LL quickPow(LL a, LL b, LL MOD) {
    LL ret = 1LL;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
int main() {
    scanf("%lld", &n);
    ans = 1LL;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        ans = ans * (a[i] + 1LL) % MOD;
    }
    LL INV_2 = quickPow(2LL, MOD - 2, MOD);
    for (int i = 1; i <= n; ++i)
        ans = (ans + a[i] * (a[i] + 1LL) % MOD * INV_2 % MOD) % MOD;
    printf("%lld\n", ans);
    return 0;
}