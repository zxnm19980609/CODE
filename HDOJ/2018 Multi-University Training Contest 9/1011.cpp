#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
LL a, b, c, d;
LL quickPow(LL a, LL b) {
    LL ret = 1LL;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret % MOD;
}
int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d;
        LL ans = quickPow(2LL, a + b) % MOD;
        if (c >= 1)
            ans = (ans + quickPow(2LL, a) * (quickPow(2LL, c) + MOD - 1) % MOD * (b + 1) % MOD) % MOD;
        if (d >= 1)
            ans = (ans + d * quickPow(2LL, a + c) % MOD) % MOD;
        cout << ans % MOD << endl;
    }
    return 0;
}