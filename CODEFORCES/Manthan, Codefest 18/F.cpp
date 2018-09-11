#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, k, a[MAXN], g[MAXN], cnt[MAXN];
LL ans = 0LL;
void solve(int l, int r) {
    if (l >= r) return;
    int m = (l + r) >> 1;
    solve(l, m);
    solve(m + 1, r);
    g[m] = a[m];
    for (int i = m - 1; i >= l; --i)
        g[i] = max(g[i + 1], a[i]);
    g[m + 1] = a[m + 1];
    for (int i = m + 2; i <= r; ++i)
        g[i] = max(g[i - 1], a[i]);
    int cl, cr;
    for (int i = l; i <= r; ++i)
        cnt[i % k] = 0;
    cl = m + 1;
    for (cr = m + 1; cr <= r; ++cr) {
        while (cl - 1 >= l && g[cl - 1] <= g[cr]) {
            --cl;
            ++cnt[cl % k];
        }
        ans = (ans + (LL)cnt[cr % k] * g[cr]) % MOD;
    }
    for (int i = l; i <= r; ++i)
        cnt[i % k] = 0;
    cr = m;
    for (cl = m; cl >= l; --cl) {
        while (cr + 1 <= r && g[cr + 1] < g[cl]) {
            ++cr;
            ++cnt[cr % k];
        }
        ans = (ans + (LL)cnt[cl % k] * g[cl]) % MOD;
    }
}
int main() {
    scanf("%d%d", &n, &k);
    --k;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    solve(1, n);
    ans = (ans % MOD + MOD) % MOD;
    printf("%I64d\n", ans);
    return 0;
}