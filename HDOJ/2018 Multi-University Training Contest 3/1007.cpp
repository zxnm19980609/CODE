#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 200010;
class Point {
public:
    int x, y, id;
    Point() {}
    Point(int x, int y, int id) : x(x), y(y), id(id) {}
    Point operator-(const Point &b) const {
        return Point(x - b.x, y - b.y, 0);
    }
}p[MAXN], ch[MAXN];
int n, ans[MAXN];
bool vis[MAXN];
long long cross(const Point &a, const Point &b) {
    return (long long)a.x * b.y - (long long)b.x * a.y;
}
bool cmp(const Point &a, const Point &b) {
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y > b.y;
    return a.id < b.id;
}
void solve() {
    sort(p + 1, p + n + 1, cmp);
    int m = 0;
    for (int i = 1; i <= n; ++i) {
        if (i > 1 && p[i].x == p[i - 1].x) continue;
        while (m > 1 && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) > 0) --m;
        ch[m++] = p[i];
    }
    memset(vis, 0, sizeof vis);
    vis[0] = vis[m - 1] = 1;
    ans[0] = 1;
    ans[m - 1] = n;
    for (int i = 1; i < m - 1; ++i)
        if (cross(ch[i] - ch[i - 1], ch[i + 1] - ch[i - 1]) != 0) vis[i] = 1;
    for (int i = m - 2; i; --i)
        if (vis[i])
            ans[i] = ch[i].id;
        else
            ans[i] = min(ans[i + 1], ch[i].id);
    for (int i = 0; i < m - 1; ++i)
        if (ans[i] == ch[i].id)
            printf("%d ", ans[i]);
    printf("%d\n", n);
}
int main() {
    // freopen("in.txt", "r", stdin);
    int _;
    for (scanf("%d", &_); _; --_) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &p[i].x, &p[i].y);
            p[i].id = i;
        }
        solve();
    }
    return 0;
}