#include <bits/stdc++.h>
using namespace std;
using LL = long long;
namespace SAM {
    const int CHAR = 10;
    const int MAXL = 2e6 + 5;
    const int MOD = 1e9 + 7;
    class SAMNode {
    public:
        int fail, len, pos;
        LL cnt;
        int next[CHAR + 1];
        void clear() {
            fail = len = pos = 0;
            memset(next, 0, sizeof next);
            cnt = 0;
        }
    }sam[MAXL << 1];
    int last, root, num;
    char s[MAXL];
    int deg[MAXL << 1], valid[MAXL << 1];
    LL ans, val[MAXL << 1];
    queue<int> que;
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
    void extend(int x) {
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
        last = np;
    }
    /*
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
    */
    void solve() {
        int n;
        scanf("%d", &n);
        SAMInit();
        for (int i = 1; i <= n; ++i) {
            scanf("%s", s);
            for (int j = 0; s[j]; ++j)
                extend(s[j] - '0');
            extend(10);
        }
        for (int i = 1; i <= num; ++i)
            for (int j = 0; j < CHAR; ++j)
                ++deg[sam[i].next[j]];
        for (int i = 1; i <= num; ++i)
            if (deg[i] == 0) que.push(i);
        valid[1] = 1;
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            for (int i = 0; i < CHAR; ++i)
                if (sam[now].next[i]) {
                    valid[sam[now].next[i]] += valid[now];
                    val[sam[now].next[i]] += val[now] * 10 + (LL)valid[now] * i;
                    val[sam[now].next[i]] %= MOD;
                    if (--deg[sam[now].next[i]] == 0) que.push(sam[now].next[i]);
                }
        }
        for (int i = 1; i <= num; ++i)
            ans = (ans + val[i]) % MOD;
        printf("%lld\n", ans);
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    SAM::solve();
    return 0;
}