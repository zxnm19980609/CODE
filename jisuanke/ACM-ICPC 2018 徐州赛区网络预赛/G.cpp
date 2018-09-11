#include <bits/stdc++.h>
#define lson p << 1
#define rson p << 1 | 1
using namespace std;
using LL = long long;
const int MAXN = 100005;
class SegmentTree {
public:
    int left, right, val, tag;
}tree[MAXN << 2];
int n, m, b[MAXN];
pair<int, int> wave[MAXN];
void build(int p, int l, int r) {
    tree[p].left = l;
    tree[p].right = r;
    tree[p].val = 0;
    tree[p].tag = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}
void pushdown(int p) {
    if (tree[p].tag) {
        tree[lson].val = tree[p].tag;
        tree[rson].val = tree[p].tag;
        tree[lson].tag = tree[p].tag;
        tree[rson].tag = tree[p].tag;
        tree[p].tag = 0;
    }
}
void update(int p, int l, int r, int c) {
    if (tree[p].left == l && tree[p].right == r) {
        tree[p].val = c;
        tree[p].tag = c;
        return;
    }
    pushdown(p);
    int mid = (tree[p].left + tree[p].right) >> 1;
    if (r <= mid)
        update(lson, l, r, c);
    else if (l > mid)
        update(rson, l, r, c);
    else {
        update(lson, l, mid, c);
        update(rson, mid + 1, r, c);
    }
    tree[p].val = max(tree[lson].val, tree[rson].val);
}
int query(int p, int l, int r) {
    if (tree[p].left == l && tree[p].right == r)
        return tree[p].val;
    pushdown(p);
    int mid = (tree[p].left + tree[p].right) >> 1;
    if (r <= mid)
        return query(lson, l, r);
    else if (l > mid)
        return query(rson, l, r);
    else
        return max(query(lson, l, mid), query(rson, mid + 1, r));
}
int binarySearch(int l, int r, int x) {
    int ret = 0, m;
    while (l <= r) {
        m = (l + r) >> 1;
        if (query(1, m, r) >= x) {
            ret = max(ret, m);
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return ret;
}
int main() {
    scanf("%d", &n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &wave[i].first, &wave[i].second);
        b[m++] = wave[i].first;
        b[m++] = wave[i].second;
    }
    sort(b, b + m);
    m = unique(b, b + m) - b;
    for (int i = 0; i < n; ++i) {
        wave[i].first = lower_bound(b, b + m, wave[i].first) - b + 1;
        wave[i].second = lower_bound(b, b + m, wave[i].second) - b + 1;
    }
    LL ans = 0;
    build(1, 1, m);
    for (int i = n - 1; ~i; --i) {
        int pos = binarySearch(1, wave[i].first, wave[i].second);
        if (!pos)
            ans += b[wave[i].first - 1];
        else
            ans += b[wave[i].first - 1] - b[pos - 1];
        update(1, pos + 1, wave[i].first, wave[i].second);
    }
    build(1, 1, m);
    for (int i = n - 1; ~i; --i) {
        int pos = binarySearch(1, wave[i].second, wave[i].first);
        if (!pos)
            ans += b[wave[i].second - 1];
        else
            ans += b[wave[i].second - 1] - b[pos - 1];
        update(1, pos + 1, wave[i].second, wave[i].first);
    }
    printf("%lld\n", ans);
    return 0;
}