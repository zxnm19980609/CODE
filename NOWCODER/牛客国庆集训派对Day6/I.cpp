#include <bits/stdc++.h>
#define lson p << 1
#define rson p << 1 | 1
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 0x3F3F3F3F;
class STNode {
public:
    int left, right, tag;
    int val;
}tree[MAXN << 2];
class Edge {
public:
    int to, next;
}edge[MAXN << 1];
int cnt, h[MAXN];
int ct, siz[MAXN], top[MAXN], son[MAXN], dep[MAXN], faz[MAXN], tid[MAXN], rnk[MAXN];
int n, m, k, ans[MAXN];
tuple<int, int, int> opt[MAXN];
void init() {
    cnt = ct = 0;
    memset(h, 0, sizeof h);
    memset(son, -1, sizeof son);
    memset(ans, 0, sizeof ans);
}
void build(int p, int l, int r) {
    tree[p].left = l;
    tree[p].right = r;
    tree[p].tag = tree[p].val = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}
void pushdown(int p) {
    if (tree[p].tag) {
        tree[lson].val += tree[p].tag;
        tree[rson].val += tree[p].tag;
        tree[lson].tag += tree[p].tag;
        tree[rson].tag += tree[p].tag;
        tree[p].tag = 0;
    }
}
void update(int p, int l, int r) {
    if (tree[p].left == l && tree[p].right == r) {
        ++tree[p].val;
        ++tree[p].tag;
        return;
    }
    pushdown(p);
    int mid = (tree[p].left + tree[p].right) >> 1;
    if (r <= mid)
        update(lson, l, r);
    else if (l > mid)
        update(rson, l, r);
    else {
        update(lson, l, mid);
        update(rson, mid + 1, r);
    }
    tree[p].val = max(tree[lson].val, tree[rson].val);
}
void addEdge(int u, int v) {
    ++cnt;
    edge[cnt].to = v;
    edge[cnt].next = h[u];
    h[u] = cnt;
    swap(u, v);
    ++cnt;
    edge[cnt].to = v;
    edge[cnt].next = h[u];
    h[u] = cnt;
}
void dfs1(int u, int fa, int d) {
    dep[u] = d;
    faz[u] = fa;
    siz[u] = 1;
    for (int p = h[u]; p; p = edge[p].next) {
        int v = edge[p].to;
        if (v == faz[u]) continue;
        dfs1(v, u, d + 1);
        siz[u] += siz[v];
        if (son[u] == -1 || siz[v] > siz[son[u]])
            son[u] = v;
    }
}
void dfs2(int u, int t) {
    top[u] = t;
    tid[u] = ++ct;
    rnk[ct] = u;
    if (son[u] == -1) return;
    dfs2(son[u], t);
    for (int p = h[u]; p; p = edge[p].next) {
        int v = edge[p].to;
        if (v == faz[u]) continue;
        if (v != son[u]) dfs2(v, v);
    }
}
void updatePath(int u, int v, int c) {
    int tu = top[u], tv = top[v];
    while (tu != tv) {
        if (dep[tu] > dep[tv]) {
            update(1, tid[tu], tid[u]);
            u = faz[tu];
            tu = top[u];
        }
        else {
            update(1, tid[tv], tid[v]);
            v = faz[tv];
            tv = top[v];
        }
    }
    if (tid[u] < tid[v])
        update(1, tid[u], tid[v]);
    else
        update(1, tid[v], tid[u]);
}
void find(int p, int c) {
    if (tree[p].val < k) return;
    if (tree[p].left == tree[p].right) {
        ans[rnk[tree[p].left]] = c;
        tree[p].val = -INF;
        return;
    }
    pushdown(p);
    int mid = (tree[p].left + tree[p].right) >> 1;
    find(lson, c);
    find(rson, c);
    tree[p].val = max(tree[lson].val, tree[rson].val);
}
void solve(int u, int v, int c) {
    updatePath(u, v, c);
    find(1, c);
}
int main() {
    init();
    scanf("%d%d%d", &n, &m, &k);
    for (int u, v, i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, 1, ct);
    for (int u, v, c, i = 1; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &c);
        opt[i] = make_tuple(u, v, c);
    }
    for (int u, v, c, i = m; i; --i) {
        tie(u, v, c) = opt[i];
        solve(u, v, c);
    }
    for (int i = 1; i <= n; ++i)
        printf(i == n ? "%d\n" : "%d ", ans[i]);
    return 0;
}