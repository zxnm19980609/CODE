#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 100005;
const int MOD = 1e9 + 7;
char s[MAXN];
LL quickPow(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        LL val = 0;
        for (int i = 0; s[i]; ++i)
            val = (val * 10 + (s[i] - '0')) % (MOD - 1);
        val = (val - 1 + MOD) % MOD;
        printf("%lld\n", quickPow(2LL, val));
    }
    return 0;
}