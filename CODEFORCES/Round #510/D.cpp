#include <bits/stdc++.h>
#define lson p << 1
#define rson p << 1 | 1
using namespace std;
using LL = long long;
const int MAXN = 2e5 + 5;
class Node {
public:
    int left, right, sum;
}segtree[(MAXN << 2) + 5];
int n, m;
LL a[MAXN], b[MAXN];
void build(int p, int l, int r) {
    segtree[p].left = l;
    segtree[p].right = r;
    segtree[p].sum = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}
void update(int p, int x) {
    if (segtree[p].left == segtree[p].right) {
        ++segtree[p].sum;
        return;
    }
    int mid = (segtree[p].left + segtree[p].right) >> 1;
    if (x <= mid)
        update(lson, x);
    else
        update(rson, x);
    segtree[p].sum = segtree[lson].sum + segtree[rson].sum;
}
int query(int p, int x) {
    if (segtree[p].right <= x)
        return segtree[p].sum;
    int mid = (segtree[p].left + segtree[p].right) >> 1;
    if (x <= mid)
        return query(lson, x);
    else
        return query(lson, x) + query(rson, x);
}
inline int lsh(LL x) {
    return upper_bound(b + 1, b + m + 1, x) - b;
}
int main() {
    LL t, ans = 0;
    scanf("%d%lld", &n, &t);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    m = unique(b + 1, b + n + 1) - (b + 1);
    build(1, 1, m);
    for (int i = n; i; --i) {
        update(1, lsh(a[i]));
        int x = lsh(a[i - 1] + t) - 1;
        printf("q %d\n",  query(1, x));
        ans += query(1, lsh(a[i - 1] + t) - 1);
    }
    printf("%lld\n", ans);
    return 0;
}