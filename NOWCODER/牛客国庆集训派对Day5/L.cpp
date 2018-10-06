#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        LL n, a, k, s;
        scanf("%lld%lld", &n, &k);
        a = LL(sqrt(4LL * n + 1LL) - 1LL);
        printf("%lld ", a);
        if (k > a / 2)
            printf("%lld\n", a - k + 1);
        else
            printf("%lld\n", n / k);
    }
    return 0;
}