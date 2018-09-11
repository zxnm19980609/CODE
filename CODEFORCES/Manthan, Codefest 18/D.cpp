#include <bits/stdc++.h>
#define lson p << 1
#define rson p << 1 | 1
using namespace std;
const int MAXN = 2e5 + 5;
const int INF = 0x3F3F3F3F;
class SegmentTree {
public:
    int left, right, val;
}segtree[MAXN << 2];
int n, cnt, a[MAXN], val[MAXN];
bool vis[MAXN];
vector<int> edge[MAXN];
void build(int p, int l, int r) {
    segtree[p].left = l;
    segtree[p].right = r;
    if (l == r) {
        segtree[p].val = INF;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson,mid + 1, r);
    segtree[p].val = min(segtree[lson].val, segtree[rson].val);
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
    scanf("%d", &n);
    for (int u, v, i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        val[i] = INF;
    build(1, 1, n);
    val[1] = cnt;
    update(1, 1, cnt);
    vis[1] = true;
    ++cnt;
    for (int i = 1; i <= n; ++i) {
        if (val[a[i]] == segtree[1].val) {
            for (auto& v : edge[a[i]])
                if (!vis[v]) {
                    vis[v] = true;
                    val[v] = cnt;
                    update(1, v, cnt);
                }
            ++cnt;
            update(1, a[i], INF);
        }
        else {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}