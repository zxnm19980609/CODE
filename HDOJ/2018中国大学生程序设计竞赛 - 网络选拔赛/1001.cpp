#include <bits/stdc++.h>
#define lson p << 1
#define rson p << 1 | 1
using namespace std;
const int MAXN = 1e5 + 5;
int n, opt[MAXN];
class SegmentTree {
public:
    int left, right, val, tag;
}tree[MAXN << 2];
pair<int, int> a[MAXN];
map<int, int> mp;
void build(int p, int l, int r) {
    tree[p].left = l;
    tree[p].right = r;
    tree[p].tag = 0;
    if (l == r) {
        tree[p].val = tree[p].left;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    tree[p].val = min(tree[lson].val, tree[rson].val);
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
        return min(query(lson, l, mid), query(rson, mid + 1, r));
}
void update(int p, int l, int r, int c) {
    if (tree[p].left == l && tree[p].right == r) {
        tree[p].val += c;
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
    tree[p].val = min(tree[lson].val, tree[rson].val);
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        build(1, 1, n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i].first);
            a[i].second = i;
            opt[i] = 1;
        }
        sort(a + 1, a + n + 1, [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        });
        for (int i = 1; i <= n; ++i) {
            int mi = query(1, a[i].second, n);
            if (mi >= 2) {
                opt[a[i].second] = -1;
                update(1, a[i].second, n, -2);
            }
            else if (mi == 1) {
                opt[a[i].second] = 0;
                update(1, a[i].second, n, -1);
            }
        }
        sort(a + 1, a + n + 1, [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        });
        long long ans = 0;
        int cnt = 0;
        mp.clear();
        map<int, int>::iterator mit;
        for (int i = 1; i <= n; ++i) {
            ans = ans - opt[i] * a[i].first;
            cnt += (opt[i] == 0 ? 0 : 1);
            if (opt[i] == -1)
                ++mp[a[i].first];
            else if (opt[i] == 1) {
                mit = mp.find(a[i].first);
                if (mit != mp.end() && mit->second > 0) {
                    cnt -= 2;
                    --(mit->second);
                }
            }
        }
        printf("%lld %d\n", ans, cnt);
    }
    return 0;
}