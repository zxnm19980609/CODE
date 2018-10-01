#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAX = 1e5 + 5;
LL a, b, c, p1, p2, q1, q2, exGcd_x, exGcd_y, exGcd_d;
void exGcd(LL a, LL b) {
    if (b == 0) {
        exGcd_x = 1;
        exGcd_y = 0;
        exGcd_d = a;
    }
    else {
        exGcd(b, a % b);
        LL tmp = exGcd_x;
        exGcd_x = exGcd_y;
        exGcd_y = tmp - a / b * exGcd_y;
    }
}
int main() {
    cin >> a >> b >> c >> p1 >> p2 >> q1 >> q2;
    LL gcd = __gcd(a, b);
    if (c % gcd)
        cout << "Kuon" << endl;
    else {
        exGcd(a, b);
        LL x1, y1, ag, bg;
        ag = a / gcd;
        bg = b / gcd;
        x1 = (exGcd_x + bg) * (c / gcd);
        x1 = (x1 % bg + bg) % bg;
        y1 = (c - a * x1) / b;
        LL ans = LLONG_MAX;
        for (int i = 1; i <= MAX; ++i) {
            if (x1 > MAX || y1 > MAX) break;
            ans = min(ans, p2 * x1 * x1 + p1 * x1 + q2 * y1 * y1 + q1* y1);
            x1 -= bg;
            y1 += ag;
        }
        x1 = (exGcd_x + bg) * (c / gcd);
        x1 = (x1 % bg + bg) % bg;
        y1 = (c - a * x1) / b;
        for (int i = 1; i <= MAX; ++i) {
            if (x1 > MAX || y1 > MAX) break;
            ans = min(ans, p2 * x1 * x1 + p1 * x1 + q2 * y1 * y1 + q1* y1);
            x1 += bg;
            y1 -= ag;
        }
        cout << ans << endl;
    }
    return 0;
}