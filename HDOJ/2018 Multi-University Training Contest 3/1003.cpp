#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int mod = 1e9 + 7;
int cnt[1030][15];
int ans[15];
int n, m;

int Count(int x)
{
    int ret = 0;
    while (x) {
        if (x & 1) {
            ++ ret;
        }
        x >>= 1;
    }
    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t --) {
        memset(cnt, 0, sizeof cnt);
        memset(ans, 0, sizeof ans);
        scanf("%d%d", &n, &m);
        while (m --) {
            char c;
            int u, v;
            scanf(" %c%d%d", &c, &u, &v);
            int pat = (1 << (u - 1)) | (1 << (v - 1));
            if (c == '+') {
                for (int i = 3; i < (1 << n); i ++) {
                    int pp = i ^ pat;
                    // if (pp == 0) continue;
                    if ((i & pat) == pat && ((__builtin_popcount(pp) & 1) == 0)) {
                        cnt[i][1] = (cnt[i][1] + 1) % mod;
                        ans[1] = (ans[1] + 1) % mod;
                        for (int j = 2; j <= n / 2; j ++) {
                            cnt[i][j] = (cnt[pp][j - 1] + cnt[i][j]) % mod;
                            ans[j] = (cnt[pp][j - 1] + ans[j]) % mod;
                        }
                    }
                }
            } else {
                for (int i = 3; i < (1 << n); i ++) {
                    int pp = i ^ pat;
                    // if (pp == 0) continue;
                    if ((i & pat) == pat && ((__builtin_popcount(pp) & 1) == 0)) {
                        cnt[i][1] = (cnt[i][1] - 1 + mod) % mod;
                        ans[1] = (ans[1] - 1 + mod) % mod;
                        for (int j = 2; j <= n / 2; j ++) {
                            cnt[i][j] = (-cnt[pp][j - 1] + cnt[i][j] + mod) % mod;
                            ans[j] = (-cnt[pp][j - 1] + ans[j] + mod) % mod;
                        }
                    }
                }
            }
            printf("%d", ans[1]);
            for (int i = 2; i <= n / 2; i ++) {
                printf(" %d", ans[i]);
            }
            puts("");
        }
    }
    return 0;
}