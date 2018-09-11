#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int a[25];
LL dp[25][5], l, r;
LL dfs(int pos, int cnt, bool zero, bool limit) {
    if (pos == -1) return 1;
    if (!limit && !zero && dp[pos][cnt] != -1)
        return dp[pos][cnt];
    int up = limit ? a[pos] : 9;
    if (cnt == 3) up = 0;
    LL ans = 0;
    for (int i = 0; i <= up; ++i)
        ans += dfs(pos - 1, cnt + (i == 0 ? 0 : 1), zero && i == 0, limit && i == a[pos]);
    if (!limit && !zero) dp[pos][cnt] = ans;
    return ans;
}
LL solve(LL x) {
    int pos = 0;
    while (x) {
        a[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1, 0, true, true);
}
int main() {
    int T;
    LL l, r;
    scanf("%d", &T);
    while (T--) {
        memset(dp, -1, sizeof dp);
        scanf("%I64d%I64d", &l, &r);
        printf("%I64d\n", solve(r) - solve(l - 1));
    }
    return 0;
}