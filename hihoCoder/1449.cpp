#include <bits/stdc++.h>
#define lson p << 1
#define rson p << 1 | 1
using namespace std;
namespace SAM {
    const int CHAR = 26;
    const int MAXL = 1e6 + 5;
    class SAMNode {
    public:
        int fail, len, pos, cnt, next[CHAR];
        void clear() {
            fail = len = pos = cnt = 0;
            memset(next, 0, sizeof next);
        }
    }sam[MAXL << 1];
    int last, root, num, ed[MAXL];
    char s[MAXL];
    int newNode(int len, int pos) {
        int cur = ++num;
        sam[cur].clear();
        sam[cur].len = len;
        sam[cur].pos = pos;
        return cur;
    }
    void SAMInit() {
        num = 0;
        root = last = newNode(0, 0);
    }
    int extend(int last, int x) {
        int p = last, np = newNode(sam[p].len + 1, sam[p].len + 1);
        while (p && !sam[p].next[x]) {
            sam[p].next[x] = np;
            p = sam[p].fail;
        }
        if (!p)
            sam[np].fail = root;
        else {
            int q = sam[p].next[x];
            if (sam[q].len == sam[p].len + 1)
                sam[np].fail = q;
            else {
                int nq = newNode(sam[p].len + 1, sam[p].pos);
                memcpy(sam[nq].next, sam[q].next, sizeof sam[q].next);
                sam[nq].fail = sam[q].fail;
                sam[q].fail = sam[np].fail = nq;
                while (p && sam[p].next[x] == q) {
                    sam[p].next[x] = nq;
                    p = sam[p].fail;
                }
            }
        }
        sam[np].cnt = 1;
        return np;
    }
    void calc() {
        static int deg[MAXL << 1];
        memset(deg, 0, sizeof deg);
        static queue<int> que;
        while (!que.empty()) que.pop();
        for (int i = 1; i <= num; ++i)
            ++deg[sam[i].fail];
        for (int i = 1; i <= num; ++i)
            if (!deg[i]) que.push(i);
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            int fail = sam[now].fail;
            sam[fail].cnt += sam[now].cnt;
            if (--deg[fail] == 0) que.push(fail);
        }
    }
    void build() {
        SAMInit();
        scanf("%s", s + 1);
        memset(ed, 0, sizeof ed);
        ed[0] = root;
        for (int i = 1; s[i]; ++i)
            ed[i] = extend(ed[i - 1], s[i] - 'a');
    }
}
namespace SegmentTree {
    const int MAXN = 1e6 + 5;
    class STNode {
    public:
        int left, right, val, tag;
    }tree[MAXN << 2];
    void build(int p, int l, int r) {
        tree[p].left = l;
        tree[p].right = r;
        tree[p].val = tree[p].tag = 0;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
    }
    void pushdown(int p) {
        if (tree[p].tag) {
            tree[lson].val = max(tree[lson].val, tree[p].tag);
            tree[lson].tag = max(tree[lson].tag, tree[p].tag);
            tree[rson].val = max(tree[rson].val, tree[p].tag);
            tree[rson].tag = max(tree[rson].tag, tree[p].tag);
            tree[p].tag = 0;
        }
    }
    void update(int p, int l, int r, int c) {
        if (tree[p].left == l && tree[p].right == r) {
            tree[p].val = max(tree[p].val, c);
            tree[p].tag = max(tree[p].tag, c);
            return;
        }
        pushdown(p);
        int mid = (tree[p].left + tree[p].right) >> 1;
        if (r <= mid)
            update(lson, l, r, c);
        else if (l > mid)
            update(rson, mid + 1, r, c);
        else {
            update(lson, l, mid, c);
            update(rson, mid + 1, r, c);
        }
        tree[p].val = max(tree[lson].val, tree[rson].val);
    }
    int query(int p, int x) {
        if (tree[p].left == tree[p].right)
            return tree[p].val;
        pushdown(p);
        int mid = (tree[p].left + tree[p].right) >> 1;
        if (x <= mid)
            query(lson, x);
        else
            query(rson, x);
    }
}
void solve() {
    using SAM::s;
    using SAM::sam;
    using SAM::num;
    using SegmentTree::update;
    using SegmentTree::query;
    SAM::build();
    SAM::calc();
    int n = strlen(s + 1);
    SegmentTree::build(1, 1, n);
    for (int i = 2; i <= num; ++i)
        update(1, sam[sam[i].fail].len + 1, sam[i].len, sam[i].cnt);
    for (int i = 1; i <= n; ++i)
        printf("%d\n", query(1, i));
}
int main() {
    solve();
    return 0;
}