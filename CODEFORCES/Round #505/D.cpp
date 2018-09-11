#include <bits/stdc++.h>
using namespace std;
int n, a[705];
bool g[705][705], dpL[705][705], dpR[705][705];
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            g[i][j] = (__gcd(a[i], a[j]) != 1);
    for (int i = 1; i <= n; ++i)
        dpL[i][i] = dpR[i][i] = true;
    for (int len = 2; len <= n; ++len)
        for (int l = 1; l <= n; ++l) {
            int r = l + len - 1;
            if (r > n) break;
            for (int mid = l + 1; mid <= r; ++mid)
                dpL[l][r] |= (g[l][mid] & dpL[mid][r] & dpR[l + 1][mid]);
            for (int mid = l; mid < r; ++mid)
                dpR[l][r] |= (g[r][mid] & dpL[mid][r - 1] && dpR[l][mid]);
        }
    for (int i = 1; i <= n; ++i)
        if (dpL[i][n] && dpR[1][i]) {
            puts("Yes");
            return 0;
        }
    puts("No");
    return 0;
}