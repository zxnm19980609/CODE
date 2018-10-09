#include <bits/stdc++.h>
#define lson p << 1
#define rson p << 1 | 1
using namespace std;
using LL = long long;
const int MAXN = 5e4 + 5;
class STNode {
public:
    int left, right;
    LL tag, sum;
    int len() {
        return right - left + 1;
    }
}tree[MAXN << 2];
class Edge {
public:
    int to, next;
}edge[MAXN << 1];
int cnt, h[MAXN];
int ct, siz[MAXN], top[MAXN], son[MAXN], dep[MAXN], faz[MAXN], tid[MAXN], rnk[MAXN];
int n, m, q, a[MAXN];
bool over = false;
tuple<int, int, int> opt[MAXN];
inline int nextInt() {
    int x = 0;
    char ch = getchar();
    if (ch == EOF) {
        over = true;
        return x;
    }
    bool nagtive = false;
    while(ch < '0' || ch > '9') {
        if (ch == '-') nagtive = true;
        ch = getchar();
        if (ch == EOF) {
            over = true;
            break;
        }
    }
    while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
        if (ch == EOF) {
            over = true;
            break;
        }
    }
    return nagtive ? -x : x;
}
void init() {
    cnt = ct = 0;
    memset(h, 0, sizeof h);
    memset(son, -1, sizeof son);
}
void build(int p, int l, int r) {
    tree[p].left = l;
    tree[p].right = r;
    tree[p].tag  = 0;
    if (l == r) {
        tree[p].sum = a[rnk[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    tree[p].sum = tree[lson].sum + tree[rson].sum;
}
void pushdown(int p) {
    if (tree[p].tag) {
        tree[lson].sum += tree[p].tag * tree[lson].len();
        tree[rson].sum += tree[p].tag * tree[rson].len();
        tree[lson].tag += tree[p].tag;
        tree[rson].tag += tree[p].tag;
        tree[p].tag = 0;
    }
}
LL query(int p, int x) {
    if (tree[p].left ==  tree[p].right)
        return tree[p].sum;
    pushdown(p);
    int mid = (tree[p].left + tree[p].right) >> 1;
    if (x <= mid)
        return query(lson, x);
    else if (x > mid)
        return query(rson, x);
}
void update(int p, int l, int r, LL c) {
    if (tree[p].left == l && tree[p].right == r) {
        tree[p].sum += c * tree[p].len();
        tree[p].tag += c;
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
    tree[p].sum = tree[lson].sum + tree[rson].sum;
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
            update(1, tid[tu], tid[u], c);
            u = faz[tu];
            tu = top[u];
        }
        else {
            update(1, tid[tv], tid[v], c);
            v = faz[tv];
            tv = top[v];
        }
    }
    if (tid[u] < tid[v])
        update(1, tid[u], tid[v], c);
    else
        update(1, tid[v], tid[u], c);
}
int main() {
    while (!over) {
        init();
        n = nextInt();
        m = nextInt();
        q = nextInt();
        for (int i = 1; i <= n; ++i)
            a[i] = nextInt();
        for (int u, v, i = 1; i <= m; ++i) {
            u = nextInt();
            v = nextInt();
            addEdge(u, v);
        }
        dfs1(1, 0, 1);
        dfs2(1, 1);
        build(1, 1, ct);
        while (q--) {
            int u, v, c;
            char ch = getchar();
            while (ch < 'A' || ch > 'Z') ch = getchar();
            switch (ch) {
            case 'I':
                u = nextInt();
                v = nextInt();
                c = nextInt();
                updatePath(u, v, c);
                break;
            case 'D':
                u = nextInt();
                v = nextInt();
                c = nextInt();
                c = -c;
                updatePath(u, v, c);
                break;
            case 'Q':
                u = nextInt();
                printf("%lld\n", query(1, tid[u]));
                break;
            }
        }
    }
    return 0;
}