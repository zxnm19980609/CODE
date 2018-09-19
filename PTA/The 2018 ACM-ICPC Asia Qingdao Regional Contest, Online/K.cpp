#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n, cnt[32];
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof cnt);
        for (int t, i = 1; i <= n; ++i) {
            scanf("%d", &t);
            ++cnt[__builtin_clz(t)];
        }
        int ans = 0;
        for (int i = 0; i < 32; ++i)
            ans = max(ans, cnt[i]);
        printf("%d\n", ans);
    }
    return 0;
}