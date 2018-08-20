#include <bits/stdc++.h>
#define lson p << 1
#define rson p << 1 | 1
using namespace std;
typedef long long LL;
const int MAXN = 100005;
class SegmentTree {
public:
    int left, right;
    LL ls, rs, ms;
    bool full;
}tree[MAXN << 2];
int n;
void build(int p, int l, int r) {
    tree[p].left = l;
    tree[p].right = r;
    tree[p].full = true;
    if (l == r) {
        scanf("%I64d", &tree[p].ms);
        tree[p].ls = tree[p].rs = tree[p].ms;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    tree[p].ms = tree[lson].ms + tree[rson].ms;
    tree[p].ls = tree[p].rs = tree[p].ms;
}
void update(int p, int x) {
    if (tree[p].left == tree[p].right) {
        tree[p].ls = tree[p].rs = tree[p].ms = 0;
        tree[p].full = false;
        return;
    }
    int mid = (tree[p].left + tree[p].right) >> 1;
    if (x <= mid)
        update(lson, x);
    else
        update(rson, x);
    tree[p].ms = max(tree[lson].ms, tree[rson].ms);
    tree[p].ms = max(tree[p].ms, tree[lson].rs + tree[rson].ls);
    tree[p].ls = tree[lson].ls;
    tree[p].rs = tree[rson].rs;
    if (tree[lson].full) tree[p].ls += tree[rson].ls;
    if (tree[rson].full) tree[p].rs += tree[lson].rs;
    tree[p].full = tree[lson].full && tree[rson].full;
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    build(1, 1, n);
    for (int x, i = 1; i <= n; ++i) {
        scanf("%d", &x);
        update(1, x);
        printf("%I64d\n", tree[1].ms);
    }
    return 0;
}