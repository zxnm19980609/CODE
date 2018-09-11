#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a, b, n, MOD, B;
pair<LL, LL> mul(pair<LL, LL> a, pair<LL, LL> b, LL MOD) {
    return pair<LL, LL>((a.first * b.first % MOD + a.second * b.second % MOD * B % MOD) % MOD,
                        (a.second * b.first % MOD + a.first * b.second % MOD) % MOD);
}
LL solve(LL a, LL b, LL n, LL MOD) {
    pair<LL, LL> ret(1, 0), y(a, b);
    while (n) {
        if (n & 1) ret = mul(ret, y, MOD);
        y = mul(y, y, MOD);
        n >>= 1;
    }
    return ret.second;
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld%lld", &a, &b, &n, &MOD);
        B = b;
        LL ans = solve(a, 1, n, MOD);
        LL lim = (int)floor(sqrt(B));
        for (LL j, i = 2; i <= lim; ++i) {
            j = i * i;
            while (B % j == 0) {
                ans = (ans * i) % MOD;
                B /= j;
            }
        }
        printf("1 %lld %lld\n", ans, B);
    }
    return 0;
}