#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = 1e5 + 10;
pair<int, int> seg[MAXM];
int n, m, ans[MAXN];
set<int> available;
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i)
            scanf("%d%d", &seg[i].first, &seg[i].second);
        sort(seg, seg + m);
        available.clear();
        for (int i = 1; i <= n; ++i)
            available.insert(i);
        int pl = 1, maxr = 0;
        for (int i = 0; i < m; ++i) {
            int nowl = seg[i].first;
            int nowr = seg[i].second;
            if (nowr <= maxr) continue;
            for (int j = maxr + 1; j < nowl; ++j)
                ans[j] = 1;
            for (int j = pl; j < nowl; ++j) available.insert(ans[j]);
            pl = nowl;
            for (int j = max(nowl, maxr + 1); j <= nowr; ++j) {
                ans[j] = *available.begin();
                available.erase(available.begin());
            }
            maxr = nowr;
        }
        for (int i = maxr + 1; i <= n; ++i)
            ans[i] = 1;
        for (int i = 1; i <= n; ++i)
            printf(i == n ? "%d\n" : "%d ", ans[i]);
    }
    return 0;
}
