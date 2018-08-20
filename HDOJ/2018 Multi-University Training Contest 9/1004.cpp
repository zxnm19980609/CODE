#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a, b, c, aa, bb, cc;
int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> aa >> bb >> cc;
        LL q = a + b + c;
        LL p = a * (cc - bb) + b * (aa - cc) + c * (bb - aa);
        p = -p;
        if (p == 0)
            cout << 0 << endl;
        else {
            LL absp = (p > 0 ? p : -p);
            LL g = __gcd(absp, q);
            p /= g;
            q /= g;
            if (q == 1)
                cout << p << endl;
            else
                cout << p << '/' << q << endl;
        }
    }
    return 0;
}