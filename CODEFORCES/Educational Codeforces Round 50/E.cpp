#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 1005;
class Point {
public:
    LL x, y;
    Point(LL x = 0, LL y = 0) : x(x), y(y) {}
};
class Segment {
public:
    Point a, b;
    LL A, B, C;
    Segment() : A(0), B(0), C(0) {}
    Segment(const Point &a, const Point &b) a(a), b(b), A(0), B(0), C(0) {}
    void transfer() {
        A = a.y - b.y;
        B = b.x - a.x;
        C = a.x * (b.y - a.y) - a.y * (b.x - a.x);
    }
}seg[MAXN];
map<pair<LL, LL>, int> mp;
bool getIntersection(const Segment &s, const Segment &t, Point &p) {

}
int main() {
    int n;
    scanf("%d", &n);
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d%I64d%I64d%I64d", &seg[i].a.x, &seg[i].a.y, &seg[i].b.x, &seg[i].b.y);
        seg[i].transfer();
    }
    mp.clear();
    Point pt;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (getIntersection(seg[i], seg[j], pt))
                ++mp[make_pair(pt.x, pt.y)];
    return 0;
}