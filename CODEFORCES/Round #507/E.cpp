#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 500005;
const int MOD = 1e9 + 7;
int father[MAXN];
LL n, m, k, pw[MAXN], val[MAXN];
map<LL, vector<pair<int, int>>> mp;
void init() {
    pw[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        pw[i] = (pw[i - 1] << 1) % MOD;
    for (int i = 1; i <= n; ++i)
        father[i] = i;
}
int find(int x) {
    if (x == father[x]) return x;
    return father[x] = find(father[x]);
}
int main() {
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    init();
    for (int i = 1; i <= n; ++i)
        scanf("%I64d", &val[i]);
    for (int u, v, i = 1; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        mp[val[u] ^ val[v]].push_back(make_pair(u, v));
    }
    LL ans = pw[n] * (pw[k] - (LL)mp.size() + MOD) % MOD;
    for (auto &xr : mp) {
        LL virus = xr.first;
        auto &vec = xr.second;
        int cnt = n;
        for (auto &e : vec) {
            int fv = find(e.first);
            int fu = find(e.second);
            if (fv != fu) {
                --cnt;
                father[fv] = fu;
            }
        }
        ans = (ans + pw[cnt]) % MOD;
        for (auto &e : vec) {
            father[e.first] = e.first;
            father[e.second] = e.second;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}