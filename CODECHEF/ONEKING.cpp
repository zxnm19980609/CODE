#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
pair<int, int> a[MAXN];
int main() {
    // freopen("in.txt", "r", stdin);
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d%d", &a[i].first, &a[i].second);
        sort(a, a + n);
        int ans = 0;
        int minr = a[0].second;
        for (int i = 1; i < n; ++i) {
            if (a[i].first > minr) {
                ++ans;
                minr = a[i].second;
            }
            else
                minr = min(minr, a[i].second);
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}