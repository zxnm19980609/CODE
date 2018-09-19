#include <bits/stdc++.h>
using namespace std;
namespace PalindromeTree {
    const int CHAR = 26;
    const int MAXL = 2000005;
    class PTNode {
    public:
        int cnt;
        int len;
        int fail;
        int right;
        int next[CHAR];
        void clear() {
            cnt = len = fail = right = 0;
            memset(next, 0, sizeof next);
        }
    }pool[MAXL];
    char str[MAXL];
    int num, suf;
    int newNode() {
        int cur = num++;
        pool[cur].clear();
        return cur;
    }
    void init() {
        num = 0;
        int p = newNode();
        pool[p].len = 0;
        p = pool[p].fail = newNode();
        pool[p].len = -1;
        pool[p].fail = p;
        suf = 0;
    }
    int getFail(int x, int l) {
        while (str[l - 1 - pool[x].len] != str[l])
            x = pool[x].fail;
        return x;
    }
    int extend(int x) {
        int c = str[x] - 'a';
        int p = getFail(suf, x);
        if (!pool[p].next[c]) {
            int q = newNode();
            pool[q].len = pool[p].len + 2;
            pool[q].fail = pool[getFail(pool[p].fail, x)].next[c];
            pool[q].right = pool[pool[q].fail].right + 1;
            pool[p].next[c] = q;
        }
        p = pool[p].next[c];
        ++pool[p].cnt;
        return suf = p;
    }
    void calc() {
        for (int i = num - 1; ~i; --i)
            pool[pool[i].fail].cnt += pool[i].cnt;
    }
    bool build() {
        init();
        if (scanf(" %s ", str) == EOF)
            return false;
        for (int i = 0; str[i]; ++i)
            extend(i);
        return true;
    }
    void solve() {
        while (build()) {
            int ans = 0;
            for (int i = 0; i < num; ++i)
                ans = max(ans, pool[i].len);
            printf("%d\n", ans);
        }
    }
}
int main() {
    PalindromeTree::solve();
    return 0;
}