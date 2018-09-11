#include <bits/stdc++.h>
#define lson p << 1
#define rson p << 1 | 1
using namespace std;
using LL = long long;
const int MAXN = 100005;
class SegmentTree {
public:
    int left, right;
    LL sum, csum;
}tree[MAXN << 2];
int n, q;
void build(int p, int l, int r) {
    tree[p].left = l;
    tree[p].right = r;
    if (l == r) {
        scanf("%lld", &tree[p].sum);
        tree[p].csum = tree[p].sum * (LL)(n - tree[p].left + 1);
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    tree[p].sum = tree[lson].sum + tree[rson].sum;
    tree[p].csum = tree[lson].csum + tree[rson].csum;
}
LL query(int p, int l, int r) {
    if (tree[p].left == l && tree[p].right == r)
        return tree[p].sum;
    int mid = (tree[p].left + tree[p].right) >> 1;
    if (r <= mid)
        return query(lson, l, r);
    else if (l > mid)
        return query(rson, l, r);
    else
        return query(lson, l, mid) + query(rson, mid + 1, r);
}
LL queryc(int p, int l, int r) {
    if (tree[p].left == l && tree[p].right == r)
        return tree[p].csum;
    int mid = (tree[p].left + tree[p].right) >> 1;
    if (r <= mid)
        return queryc(lson, l, r);
    else if (l > mid)
        return queryc(rson, l, r);
    else
        return queryc(lson, l, mid) + queryc(rson, mid + 1, r);
}
void update(int p, int x, int c) {
    if (tree[p].left == tree[p].right) {
        tree[p].sum = c;
        tree[p].csum = tree[p].sum * (LL)(n - tree[p].left + 1);
        return;
    }
    int mid = (tree[p].left + tree[p].right) >> 1;
    if (x <= mid)
        update(lson, x, c);
    else
        update(rson, x, c);
    tree[p].sum = tree[lson].sum + tree[rson].sum;
    tree[p].csum = tree[lson].csum + tree[rson].csum;
}
int main() {
    scanf("%d%d", &n, &q);
    build(1, 1, n);
    while (q--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a == 1)
            printf("%lld\n", queryc(1, b, c) - (LL)(n - c) * query(1, b, c));
        else
            update(1, b, c);
    }
    return 0;
}