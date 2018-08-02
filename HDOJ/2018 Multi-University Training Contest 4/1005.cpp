#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL a[15], ts[50][50], ss;
LL n, m, q, x1, y1, x2, y2;
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        for (int i = 0; i < n; ++i)
            scanf("%lld", &a[i]);
        if (n & 1)
            m = n;
        else
            m = n << 1;
        scanf("%lld", &q);
        while (q--) {
            scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
            ss = 0;
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < m; ++j) {
                    LL x = x1 + i;
                    LL y = y1 + j;
                    ts[i][j] = a[((x + y) * (x + y + 1) / 2 + x) % n];
                    ss += ts[i][j];
            }
            LL cnt = ((x2 - x1 + 1) / m) * ((y2 - y1 + 1) / m);
            LL ans = cnt * ss;
            LL rescsum = 0;
            int cy = (y2 - y1 + 1) % m;
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < cy; ++j)
                    rescsum += ts[i][j];
            ans += rescsum * ((x2 - x1 + 1) / m);
            LL resrsum = 0;
            int cx = (x2 - x1 + 1) % m;
            for (int i = 0; i < cx; ++i)
                for (int j = 0; j < m; ++j)
                    resrsum += ts[i][j];
            ans += resrsum * ((y2 - y1 + 1) / m);
            for (int i = 0; i < cx; ++i)
                for (int j = 0; j < cy; ++j)
                    ans += ts[i][j];
            printf("%lld\n", ans);
        }
    }
    return 0;
}