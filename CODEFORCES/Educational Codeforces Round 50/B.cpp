#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    long long n, m, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d%I64d%I64d", &n, &m, &k);
        if (k < max(n, m))
            puts("-1");
        else {
            long long ans = min(n, m);
            long long t = k - max(n, m);
            if (t & 1)
                ans = ans - 1 + (t - 1);
            else
                ans = ans + t;
            printf("%I64d\n", ans);
        }
    }
    return 0;
}