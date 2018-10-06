#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        int d = 0;
        for (int t, i = 0; i < n; ++i) {
            scanf("%d%d", &a[i], &t);
            d += t == 1;
        }
        sort(a, a + n, greater<int>());
        int k = min(n, min(m, d));
        double ans = 0;
        for (int i = 0; i < k; ++i)
            ans += a[i] / 2.0;
        for (int i = k; i < n; ++i)
            ans += a[i];
        printf("%.1f\n", ans);
    }
    return 0;
}