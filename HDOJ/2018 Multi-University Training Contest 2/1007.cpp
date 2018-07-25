#include <cstdio>
#include <algorithm>
#define lson p << 1
#define rson p << 1 | 1
using namespace std;
const int MAXN = 100010;
class {
public:
    int left, right, val, tag;
}segtree[MAXN << 2];
class {
public:
    int left, right, sum;
}anstree[MAXN << 2];
int n, m, b[MAXN];
void build1(int p, int l, int r) {
    segtree[p].left = l;
    segtree[p].right = r;
    segtree[p].tag = 0;
    if (l == r) {
        segtree[p].val = b[segtree[p].left];
        return;
    }
    int mid = (l + r) >> 1;
    build1(lson, l, mid);
    build1(rson, mid + 1, r);
    segtree[p].val = min(segtree[lson].val, segtree[rson].val);
}
void build2(int p, int l, int r) {
    anstree[p].left = l;
    anstree[p].right = r;
    anstree[p].sum = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build2(lson, l, mid);
    build2(rson, mid + 1, r);
}
inline void pushdown(int p) {
    if (segtree[p].tag) {
        segtree[lson].val += segtree[p].tag;
        segtree[rson].val += segtree[p].tag;
        segtree[lson].tag += segtree[p].tag;
        segtree[rson].tag += segtree[p].tag;
        segtree[p].tag = 0;
    }
}
void update1(int p, int l, int r) {
    if (segtree[p].left == l && segtree[p].right == r) {
        --segtree[p].tag;
        --segtree[p].val;
        return;
    }
    pushdown(p);
    int mid = (segtree[p].left + segtree[p].right) >> 1;
    if (r <= mid)
        update1(lson, l, r);
    else if (l > mid)
        update1(rson, l, r);
    else {
        update1(lson, l, mid);
        update1(rson, mid + 1, r);
    }
    segtree[p].val = min(segtree[lson].val, segtree[rson].val);
}
void update2(int p, int x) {
    if (anstree[p].left == anstree[p].right) {
        ++anstree[p].sum;
        return;
    }
    int mid = (anstree[p].left + anstree[p].right) >> 1;
    if (x <= mid)
        update2(lson, x);
    else
        update2(rson, x);
    anstree[p].sum = anstree[lson].sum + anstree[rson].sum;
}
void query1(int p) {
    if (segtree[p].left == segtree[p].right) {
        update2(1, segtree[p].left);
        segtree[p].val = b[segtree[p].left];
        return;
    }
    pushdown(p);
    if (!segtree[lson].val) query1(lson);
    if (!segtree[rson].val) query1(rson);
    segtree[p].val = min(segtree[lson].val, segtree[rson].val);
}
int query2(int p, int l, int r) {
    if (anstree[p].left == l && anstree[p].right == r)
        return anstree[p].sum;
    int mid = (anstree[p].left + anstree[p].right) >> 1;
    if (r <= mid)
        return query2(lson, l, r);
    else if (l > mid)
        return query2(rson, l, r);
    else
        return query2(lson, l, mid) + query2(rson, mid + 1, r);
}
int main() {
    // freopen("in.txt", "r", stdin);
    char opt[10];
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &b[i]);
        build1(1, 1, n);
        build2(1, 1, n);
        for (int l, r, i = 0; i < m; ++i) {
            scanf("%s%d%d", opt, &l, &r);
            if (opt[0] == 'a') {
                update1(1, l, r);
                if (!segtree[1].val) query1(1);
            }
            else
                printf("%d\n", query2(1, l, r));
        }
    }
    return 0;
}
