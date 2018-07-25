#include <cstdio>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const LL INV = (MOD + 1) >> 1;
LL n, res, ans;
inline bool check(LL mid) {
    LL sum = 0;
    while (mid) {
        sum += mid;
        mid >>= 1;
    }
    if (sum <= n) {
        res = n - sum;
        return true;
    }
    return false;
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        --n;
        if (!n) {
            printf("1\n");
            continue;
        }
        LL l = 1, r = n, mid, k = 0;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (check(mid)) {
                if (mid > k) k = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        ans = 0;
        for (int i = 0; i < 64; ++i) {
            LL a1 = 1LL << i;
            if (a1 > k) break;
            LL m = (k + a1) / (a1 << 1);
            a1 %= MOD;
            m %= MOD;
            LL sum = (m * a1 % MOD + m * (m - 1) % MOD * (a1 << 1) % MOD * INV % MOD) % MOD;
            ans = (ans + (i + 1LL) * sum % MOD) % MOD;
        }
        ans = (ans + res * (k + 1) % MOD) % MOD;
        printf("%lld\n", (ans + 1) % MOD);
    }
    return 0;
}
