#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL m, k, a[25], p[25], c[25], d[25], cost;
LL utr(LL a, LL b) {
    return (a + b - 1) / b;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &m, &k);
        for (int i = 1; i <= m; ++i) {
            scanf("%lld%lld", &a[i], &p[i]);
            p[i] = 100LL - p[i];
        }
        for (int i = 1; i <= k; ++i)
            scanf("%lld%lld", &c[i], &d[i]);
        LL ans = 0LL;
        for (int i = 1; i <= k; ++i) {
            cost = c[i] * d[i];
            ans += cost;
        }
        for (int i = 1; i <= m; ++i) {
            LL sum = 0LL;
            for (int j = 1; j <= k; ++j) {
                cost = c[j] * utr(d[j] * p[i], 100LL);
                sum += cost;
            }
            if (sum < a[i]) sum = a[i];
            ans = min(ans, sum);
        }
        printf("%lld\n", utr(ans, 10LL));
    }
    return 0;
}