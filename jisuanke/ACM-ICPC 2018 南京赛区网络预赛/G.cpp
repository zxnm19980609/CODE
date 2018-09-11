#include <bits/stdc++.h>
#define lson p << 1
#define rson p << 1 | 1
using namespace std;
const int MAXN = 100005;
const int INF = 0x3F3F3F3F;
class SegTree {
public:
    int left, right, val;
}segtree[MAXN << 2];
int n, m, x[MAXN];
pair<int, int> ans[MAXN];
void build(int p, int l, int r) {
    segtree[p].left = l;
    segtree[p].right = r;
    if (l == r) {
        scanf("%d", &segtree[p].val);
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson,mid + 1, r);
    segtree[p].val = min(segtree[lson].val, segtree[rson].val);
}
int query(int p, int l, int r) {
    if (segtree[p].left == l && segtree[p].right == r)
        return segtree[p].val;
    int mid = (segtree[p].left + segtree[p].right) >> 1;
    if (r <= mid)
        return query(lson, l, r);
    else if (l > mid)
        return query(rson, l, r);
    else
        return min(query(lson, l, mid), query(rson, mid + 1, r));
}
void update(int p, int x, int c) {
    if (segtree[p].left == segtree[p].right) {
        segtree[p].val = c;
        return;
    }
    int mid = (segtree[p].left + segtree[p].right) >> 1;
    if (x <= mid)
        update(lson, x, c);
    else
        update(rson, x, c);
    segtree[p].val = min(segtree[lson].val, segtree[rson].val);
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    int q, maxx = 0;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d", &x[i]);
        maxx = max(maxx, x[i]);
    }
    int res = 0, cnt = 0;
    for (int i = 1; i <= maxx; ++i) {
        if (cnt < n) res += m;
        int last = 1, p, l, r;
        while (true) {
            p = n + 1, l = last, r = n;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (query(1, l, mid) <= res) {
                    p = min(p, mid);
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            if (p != n + 1) {
                res -= query(1, p, p);
                update(1, p, INF);
                ++cnt;
            }
            else
                break;
            last = p + 1;
        }
        ans[i].first = cnt;
        ans[i].second = res;
    }
    for (int i = 0; i < q; ++i)
        printf("%d %d\n", ans[x[i]].first, ans[x[i]].second);
    return 0;
}