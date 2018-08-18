#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 100005;
int n;
LL a[MAXN];
int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    LL ans, tans, a1, a2, ak, d;
    ans = LLONG_MAX;
    for (int i = -1; i < 2; ++i)
        for (int j = -1; j < 2; ++j) {
            bool flag = true;
            a1 = a[1] + i;
            a2 = a[2] + j;
            d = a2 - a1;
            ak = a2 + d;
            tans = 0;
            for (int k = 3; k <= n; ++k) {
                if ((LL)abs(a[k] - ak) == 0LL)
                    ;
                else if ((LL)abs(a[k] - ak) == 1LL)
                    ++tans;
                else {
                    flag = false;
                    break;
                }
                ak += d;
            }
            if (flag) ans = min(ans, tans + (i != 0) + (j != 0));
        }
    if (ans == LLONG_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}