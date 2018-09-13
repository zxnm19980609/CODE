#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
int a[MAXN], dp[MAXN];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = m + 1; i <= n; ++i)
        dp[i] = max(dp[i - 1], dp[i - m] + a[i]);
    printf("%d\n", dp[n]);
    return 0;
}