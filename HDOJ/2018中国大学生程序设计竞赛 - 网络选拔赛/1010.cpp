#include <bits/stdc++.h>
#define lson p << 1
#define rson p << 1 | 1
using namespace std;
const int MAXN = 1e5 + 10;
class Village {
public:
    int x, y, v;
}a[MAXN];
class SegmentTree {
public:
    int left, right, val;
}tree[MAXN << 2];
int n, b[MAXN];
vector<Village> tmp;
bool cmp(const Village &a, const Village &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int discretization() {
    for (int i = 1; i <= n; ++i)
        b[i] = a[i].y;
    sort(b + 1, b + n + 1);
    int m = unique(b + 1, b + n + 1) - (b + 1);
    for (int i = 1; i <= n; ++i)
        a[i].y = lower_bound(b + 1, b + m + 1, a[i].y) - b;
    return m;
}
void build(int p, int l, int r) {
    tree[p].left = l;
    tree[p].right = r;
    tree[p].val = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}
void update(int p, int x, int c) {
    if (tree[p].left == tree[p].right) {
        tree[p].val = max(tree[p].val, c);
        return;
    }
    int mid = (tree[p].left + tree[p].right) >> 1;
    if (x <= mid)
        update(lson, x, c);
    else
        update(rson, x, c);
    tree[p].val = max(tree[lson].val, tree[rson].val);
}
int query(int p, int l, int r) {
    if (l > r) return 0;
    if (tree[p].left == l && tree[p].right == r)
        return tree[p].val;
    int mid = (tree[p].left + tree[p].right) >> 1;
    if (r <= mid)
        return query(lson, l, r);
    else if (l > mid)
        return query(rson, l, r);
    else
        return max(query(lson, l, mid), query(rson, mid + 1, r));
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
        sort(a + 1, a + n + 1, cmp);
        int m = discretization();
        build(1, 1, m);
        tmp.clear();
        tmp.push_back(a[1]);
        for (int i = 2; i <= n; ++i) {
            if (a[i].x != a[i - 1].x) {
                for (Village& t : tmp)
                    update(1, t.y, t.v);
                tmp.clear();
            }
            a[i].v = query(1, 1, a[i].y - 1) + a[i].v;
            tmp.push_back(a[i]);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            ans = max(ans, a[i].v);
        printf("%d\n", ans);
    }
    return 0;
}