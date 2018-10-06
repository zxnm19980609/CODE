#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL cnt[105];
int main() {
    int n, d;
    scanf("%d%d", &n, &d);
    cnt[0] = 0LL;
    cnt[1] = 1LL;
    for (int i = 2; i < 61; ++i)
        cnt[i] = cnt[i - 1] + (i - d - 1 > 0 ? cnt[i - d - 1] : 0LL) + 1LL;
    LL lt = (1LL << (n - 1LL)) - 1LL;
    LL rt = d == n ? 0LL : cnt[n - d - 1];
    printf("%lld\n", lt - rt);
    return 0;
}