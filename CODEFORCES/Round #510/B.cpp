#include <bits/stdc++.h>
using namespace std;
int n, price[1005], vitamin[1005], dp[1005][8];
char s[10];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%s", &price[i], s);
        for (int j = 0; j < 3; ++j)
            if (strchr(s, 'A' + j))
                vitamin[i] |= 1 << j;
    }
    memset(dp, 0x3F, sizeof dp);
    dp[1][0] = 0;
    dp[1][vitamin[1]] = price[1];
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            for (int k = 0; k < 8; ++k) {
                dp[i][k] = min(dp[i][k], dp[j][k]);
                dp[i][k | vitamin[i]] = min(dp[i][k | vitamin[i]], dp[j][k] + price[i]);
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i)
        ans = min(ans, dp[i][7]);
    if (ans == 0x3F3F3F3F)
        puts("-1");
    else
        printf("%d\n", ans);
    return 0;
}