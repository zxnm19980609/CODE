#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    LL n, q, x, y;
    cin >> n >> q;
    while (q--) {
        cin >> x >> y;
        LL ans;
        if ((x + y) & 1) {
            LL base = (n * n + 1) / 2;
            ans = (x - 1) / 2 * n;
            if (x & 1)
                ans += y / 2;
            else
                ans += n / 2 + (y + 1) / 2;
            ans += base;
        }
        else {
            ans = (x - 1) / 2 * n;
            if (x & 1)
                ans += (y + 1) / 2;
            else
                ans += (n + 1) / 2 + y / 2;
        }
        cout << ans << endl;
    }
    return 0;
}