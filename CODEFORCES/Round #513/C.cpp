#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAX = 2005;
LL s, a[MAX], la[MAX], b[MAX], lb[MAX];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%lld", &b[i]);
        b[i] += b[i - 1];
    }
    memset(la, 0x3F, sizeof la);
    memset(lb, 0x3F, sizeof lb);
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            la[j - i + 1] = min(la[j - i + 1], a[j] - a[i - 1]);
    for (int i = 1; i <= m; ++i)
        for (int j = i; j <= m; ++j)
            lb[j - i + 1] = min(lb[j - i + 1], b[j] - b[i - 1]);
    scanf("%lld", &s);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (la[i] * lb[j] <= s) ans = max(ans, i * j);
    printf("%d\n", ans);
    return 0;
}