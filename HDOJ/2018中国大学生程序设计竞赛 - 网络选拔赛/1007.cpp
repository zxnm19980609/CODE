#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2e4 + 5;
bool vis[MAXN];
int n, m, k;
LL s, a[MAXN], sum[MAXN], tmp[MAXN];
deque<int> dq;
LL solve(LL *a, LL *sum, int n, int m) {
    sum[0] = 0;
    dq.clear();
    dq.push_back(0);
    LL mmax = 0;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
        while (!dq.empty() && sum[dq.back()] >= sum[i])
            dq.pop_back();
        dq.push_back(i);
        while (!dq.empty() && i - dq.front() > m)
            dq.pop_front();
        if (!dq.empty())
            mmax = max(mmax, sum[dq.back()] - sum[dq.front()]);
    }
    return mmax;
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int tcas = 1; tcas <= T; ++tcas) {
        printf("Case #%d: ", tcas);
        scanf("%d%lld%d%d", &n, &s, &m, &k);
        for (int i = 0; i < n; ++i)
            scanf("%lld", &a[i]);
        int loopSize = n / __gcd(n, k);
        int loopCount = m / loopSize;
        int residue = m % loopSize;
        memset(vis, 0, sizeof vis);
        LL ans = 0;
        for (int start = 0; start < n; ++start) {
            if (vis[start]) continue;
            for (int i = 1, idx = start; i <= 2 * loopSize; ++i, idx = (idx + k) % n) {
                vis[idx] = true;
                tmp[i] = a[idx];
            }
            LL mmax = solve(tmp, sum, 2 * loopSize, residue);
            ans = max(ans, sum[loopSize] * loopCount + mmax);
            mmax = solve(tmp, sum, 2 * loopSize, min(loopSize, m));
            ans = max(ans, mmax);
            ans = max(ans, sum[loopSize] * (loopCount - 1) + mmax);
        }
        printf("%lld\n", max(s - ans, 0LL));
    }
    return 0;
}