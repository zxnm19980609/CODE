#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN];
int main() {
    // freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d", &n);
    m = n << 1;
    for (int i = 0; i < m; ++i)
        scanf("%d", &a[i]);
    sort(a, a + m);
    long long ans = (long long)(a[n - 1] - a[0]) * (a[m - 1] - a[n]);
    for (int i = 1; i < n; ++i)
        ans = min(ans, (long long)(a[i + n - 1] - a[i]) * (a[m - 1] - a[0]));
    printf("%I64d\n", ans);
    return 0;
}