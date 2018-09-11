#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXL = 2000005;
const int MAXC = 10;
const int MOD = 1000000007;
LL _10e[MAXL];
char str[MAXL];
class PalindromeTree {
public:
    bool vis[MAXL];
    LL num[MAXL];
    int next[MAXL][10], cnt[MAXL], fail[MAXL], len[MAXL];
    int ct, suf;
    int newNode() {
        for (int i = 1; i < MAXC; ++i)
            next[ct][i] = 0;
        cnt[ct] = 0;
        fail[ct] = 0;
        return ct++;
    }
    void init() {
        ct = 0;
        int p;
        len[p = newNode()] = 0;
        p = fail[p] = newNode();
        len[p] = -1;
        fail[p] = p;
        suf = 0;
    }
    int getFail(int x, int l) {
        while (str[l - 1 - len[x]] != str[l])
            x = fail[x];
        return x;
    }
    int insert(int x) {
        int c = str[x] - '0';
        int p = getFail(suf, x);
        if (!next[p][c]) {
            int q = newNode();
            len[q] = len[p] + 2;
            fail[q] = next[getFail(fail[p], x)][c];
            next[p][c] = q;
        }
        p = next[p][c];
        cnt[p]++;
        suf = p;
        return suf;
    }
    void calc() {
        for (int i = ct - 1; ~i; --i)
            cnt[fail[i]] += cnt[i];
    }
    void dfs(int idx, LL val) {
        num[idx] = val;
        vis[idx] = true;
        for (int c = 1; c < MAXC; ++c)
            if (next[idx][c] && !vis[next[idx][c]]) {
                LL nval = (c * _10e[len[next[idx][c]] - 1] % MOD +
                           val * 10LL % MOD +
                           c) % MOD;
                dfs(next[idx][c], nval);
            }
    }
    LL solve() {
        LL ans = 0;
        memset(num, 0, sizeof num);
        memset(vis, 0, sizeof vis);
        dfs(0, 0);
        for (int c = 1; c < MAXC; ++c)
            if (next[1][c] && !vis[next[1][c]])
                dfs(next[1][c], c);
        for (int i = 0; i < ct; ++i)
            ans = (ans + num[i]) % MOD;
        return ans;
    }
}pt;
int main() {
    // freopen("in.txt", "r", stdin);
    _10e[0] = 1;
    for (int i = 1; i < MAXL; ++i)
        _10e[i] = _10e[i - 1] * 10LL % MOD;
    scanf("%s", str);
    int n = strlen(str);
    pt.init();
    for (int i = 0; i < n; ++i)
        pt.insert(i);
    pt.calc();
    LL ans = pt.solve();
    printf("%lld\n", ans);
    return 0;
}