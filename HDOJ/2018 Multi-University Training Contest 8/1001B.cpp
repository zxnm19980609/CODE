#include <cstdio>
using namespace std;
typedef long long LL;
const int MOD = 998244353;
const int N = 2e5 + 5;
LL fac[N + 10], invfac[N + 10];
LL quickPow(LL a, LL b, LL MOD) {
    LL ret = 1LL;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
void init() {
    fac[0] = 1;
    for (int i = 1; i <= N; ++i) fac[i] = fac[i - 1] * i % MOD;
    invfac[N] = quickPow(fac[N], MOD - 2, MOD);
    for (int i = N - 1; ~i; --i)
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
}
LL getC(LL a, LL b) {
    if (b > a) return 0;
    return fac[a] * invfac[b] % MOD * invfac[a - b] % MOD;
}
int main() {
    // freopen("in.txt", "r", stdin);
    init();
    int T;
    LL n, m, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld", &n, &m, &k);
        LL ans = 0;
        for (LL p = 0; p <= m; ++p) {
            if (k < p * n) break;
            LL t = getC(m, p) * getC(k - p * n + m - 1, m - 1) % MOD;
            if (p & 1)
                ans = (ans - t + MOD) % MOD;
            else
                ans = (ans + t) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}