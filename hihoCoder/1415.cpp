#include <bits/stdc++.h>
using namespace std;
using LL = long long;
namespace SAM {
    const int CHAR = 26;
    const int MAXL = 1e5 + 5;
    class SAMNode {
    public:
        int fail, len, pos;
        LL cnt;
        int next[CHAR];
        void clear() {
            fail = len = pos = 0;
            memset(next, 0, sizeof next);
            cnt = 0;
        }
    }sam[MAXL << 1];
    int last, root, num, ed[MAXL];
    char s[MAXL], t[MAXL];
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
    void solve() {
        build();
        scanf("%s", t + 1);
        int v = 1, l = 0, ans = 0;
        for (int i = 1; t[i]; ++i) {
            while (v && !sam[v].next[t[i] - 'a']) {
                v = sam[v].fail;
                l = sam[v].len;
            }
            if (sam[v].next[t[i] - 'a']) {
                v = sam[v].next[t[i] - 'a'];
                ++l;
            }
            ans = max(ans, l);
        }
        printf("%d\n", ans);
    }
}
int main() {
    SAM::solve();
    return 0;
}