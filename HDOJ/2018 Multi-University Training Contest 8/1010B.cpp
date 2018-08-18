#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 5;
int n, m, dp[MAXN], h[MAXN], mh[MAXN], pre[MAXN], stMax[MAXN][31];
bool selected[MAXN];
vector<int> v;
void init(int n) {
    for (int i = 1; i <= n; ++i)
        stMax[i][0] = h[i];
    for(int j = 1; (1 << j) <= n; ++j)
        for(int i = 1; i + (1 << j) - 1 <= n; ++i)
            stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
}
int query(int l, int r) {
    if (l > r) return -1;
    int k = floor(log2(r - l + 1));
    return max(stMax[l][k], stMax[r - (1 << k) + 1][k]);
}
int binarySearch(int l, int r, int x) {
    int ret = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (query(l, mid) > x) {
            ret = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ret;
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &h[i]);
        v.clear();
        v.push_back(h[1]);
        pre[1] = 1;
        mh[1] = h[1];
        selected[1] = true;
        for (int i = 2; i <= n; ++i) {
            if (h[i] > *v.rbegin()) {
                v.push_back(h[i]);
                selected[i] = true;
            }
            else
                selected[i] = false;
            pre[i] = v.size();
            mh[i] = max(mh[i - 1], h[i]);
        }
        init(n);
        dp[n] = 1;
        for (int i = n - 1; i; --i) {
            int p = binarySearch(i + 1, n, h[i]);
            if (~p)
                dp[i] = dp[p] + 1;
            else
                dp[i] = 1;
        }
        while (m--) {
            int p, q, ans;
            scanf("%d%d", &p, &q);
            int idx = binarySearch(p + 1, n, max(q, mh[p - 1]));
            if (~idx)
                ans = dp[idx];
            else
                ans = 0;
            if (q > mh[p - 1]) ++ans;
            ans += pre[p - 1];
            printf("%d\n", ans);
        }
    }
    return 0;
}