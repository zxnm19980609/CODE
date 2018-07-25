#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 10010;
pair<pair<int, int>, int> pts[MAXN];
int main() {
    // freopen("in.txt", "r", stdin);
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < 3 * n; ++i) {
            scanf("%d%d", &pts[i].first.first, &pts[i].first.second);
            pts[i].second = i + 1;
        }
        sort(pts, pts + 3 * n);
        for (int i = 0; i < n; ++i)
            printf("%d %d %d\n", pts[3 * i].second, pts[3 * i + 1].second, pts[3 * i + 2].second);
    }
    return 0;
}
