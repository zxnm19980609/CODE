#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAX = 1e6 + 5;
const int MOD = 1e9 + 7;
int cnt;
LL n, m, prime[MAX];
LL quickPow(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
LL inv(LL x) {
    return quickPow(x, MOD - 2);
}
void getP(LL n) {
    cnt = 0;
    for(LL i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            prime[cnt++] = i;
            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1) prime[cnt++] = n;
}
LL cal_1(LL x) {
    return x * (x + 1) % MOD * inv(2) % MOD;
}
LL cal_2(LL x) {
    return x * (x + 1) % MOD * (2 * x + 1) % MOD * inv(6) % MOD;
}
LL solve() {
    LL sum = 0;
    for (int i = 1; i < (1 << cnt); ++i) {
        LL f = 0, t = 1;
        for (int j = 0; j < cnt; ++j) {
            if (i & (1 << j)) {
                t *= prime[j];
                ++f;
            }
        }
        if (f & 1) {
            sum = (sum + t * t % MOD * cal_2(n / t) % MOD) % MOD;
            sum = (sum + t * cal_1(n / t) % MOD) % MOD;
        }
        else {
            sum = (sum - t * t % MOD * cal_2(n / t) % MOD + MOD) % MOD;
            sum = (sum - t * cal_1(n / t) % MOD + MOD) % MOD;
        }
    }
    return sum;
}
int main() {
    while(~scanf("%lld%lld", &n, &m)) {
        if(n == 1) {
            puts("2");
            continue;
        }
        getP(m);
        printf("%lld\n", ((cal_1(n) + cal_2(n) - solve()) % MOD + MOD) % MOD);
    }
    return 0;
}