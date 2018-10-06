#include <bits/stdc++.h>
using namespace std;
using LL = long long;
inline LL mul(LL x,LL y,LL MOD){
    LL tmp = (x*y-(LL)(((long double)x*y+0.5)/MOD)*MOD)%MOD;
    return tmp < 0 ? tmp + MOD : tmp;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        LL a, a0, a1, m0, m1, c, MOD, k;
        scanf("%lld%lld%lld%lld%lld%lld%lld", &a0, &a1, &m0, &m1, &c, &MOD, &k);
        LL ans = 1;
        ans = mul(ans, a0, MOD);
        ans = mul(ans, a1, MOD);
        for (register int i = 2; i <= k; ++i) {
            a = mul(m0, a1, MOD) + mul(m1, a0, MOD);
            a = a > MOD ? a - MOD : a;
            a += c;
            a = a > MOD ? a - MOD : a;
            ans = mul(ans, a, MOD);
            a0 = a1;
            a1 = a;
        }
        printf("%lld\n", ans);
    }
    return 0;
}