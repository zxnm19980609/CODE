#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
int n, m, ans[10], cnt[1030][10];
int main() {
    // freopen("in.txt", "r", stdin);
    int _;
    for (scanf("%d", &_); _; --_) {
        memset(cnt, 0, sizeof cnt);
        memset(ans, 0, sizeof ans);
        scanf("%d%d", &n, &m);
        while (m--) {
            char opt[5];
            int u, v;
            scanf("%s%d%d", opt, &u, &v);
            int pat = (1 << (u - 1)) | (1 << (v - 1));
            if (opt[0] == '+') {
                for (int i = 3; i < (1 << n); ++i) {
                    int pp = i ^ pat;
                    if ((i & pat) == pat && ((__builtin_popcount(pp) & 1) == 0)) {
                        cnt[i][1] = (cnt[i][1] + 1) % MOD;
                        if (!pp) ans[1] = (ans[1] + 1) % MOD;
                        for (int j = 2; j <= (n >> 1); ++j) {
                            cnt[i][j] = (cnt[i][j] + cnt[pp][j - 1]) % MOD;
                            if (i == (1 << n) - 1) ans[j] = (ans[j] + cnt[pp][j - 1]) % MOD;
                        }
                    }
                }
            }
            else {
                for (int i = 3; i < (1 << n); i ++) {
                    int pp = i ^ pat;
                    if ((i & pat) == pat && ((__builtin_popcount(pp) & 1) == 0)) {
                        cnt[i][1] = (cnt[i][1] - 1 + MOD) % MOD;
                        if (!pp) ans[1] = (ans[1] - 1 + MOD) % MOD;
                        for (int j = 2; j <= n / 2; j ++ ) {
                            cnt[i][j] = (-cnt[pp][j - 1] + cnt[i][j] + MOD) % MOD;
                            if (i == (1 << n) - 1) ans[j] = (ans[j] - cnt[pp][j - 1] + MOD) % MOD;
                        }
                    }
                }
            }
            for (int i = 1; i <= (n >> 1); ++i)
                printf(i == (n >> 1) ? "%d\n" : "%d ", ans[i]);
        }
    }
    return 0;
}