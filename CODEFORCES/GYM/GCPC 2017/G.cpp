#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 100005;
class Point {
public:
    LL x, y;
    Point(LL x = 0, LL y = 0) : x(x), y(y) {}
    Point operator-(const Point &point) const {
        return Point(x - point.x, y - point.y);
    }
    LL operator^(const Point &point) const {
        return x * point.y - y * point.x;
    }
};
int n;
Point pts[MAXN];
LL calc(Point a, Point b) {
    return __gcd(abs(a.x - b.x), abs(a.y - b.y));
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%lld", &pts[i].x, &pts[i].y);
    LL area = 0;
    for (int i = 3; i <= n; ++i)
        area += (pts[i] - pts[1]) ^ (pts[i - 1] - pts[1]);
    LL cnt = 0;
    pts[0] = pts[n];
    for (int i = 1; i <= n; ++i)
        cnt += calc(pts[i], pts[i - 1]);
    printf("%lld\n", (abs(area) - cnt + 2) / 2);
    return 0;
}