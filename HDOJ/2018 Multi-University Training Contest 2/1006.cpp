#include <cstdio>
using namespace std;
typedef long long LL;
const int MOD = 998244353;
const int MAX = 3000;
int C[MAX + 5][MAX + 5], rC[MAX + 5][MAX + 5], pw[MAX * MAX + 5];
void init() {
    C[0][0] = C[1][0] = C[1][1] = 1;
    for (int i = 2; i <= MAX; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            if (C[i][j] >= MOD) C[i][j] -= MOD;
        }
    }
    for (int i = 0; i <= MAX; ++i)
        for (int j = 0; j <= i; ++j)
            rC[j][i] = C[i][j];
    int MAX2 = MAX * MAX;
    pw[0] = 1;
    for (int i = 1; i <= MAX2; ++i) {
        pw[i] = pw[i - 1] << 1;
        if (pw[i] >= MOD) pw[i] -= MOD;
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    init();
    int n, m, a, b, t;
    while (~scanf("%d%d%d%d", &n, &m, &a, &b)) {
        int ans = 0;
        for (int i = a; i <= n; ++i)
            for (int j = b; j <= m; ++j) {
                t = (LL)rC[a - 1][i - 1] * rC[b - 1][j - 1] % MOD * C[n][i] % MOD * C[m][j] % MOD * pw[(n - i) * (m - j)] % MOD;
                if ((i - a + j - b) & 1)
                    ans -= t;
                else
                    ans += t;
                if (ans < 0) ans += MOD;
                if (ans >= MOD) ans -= MOD;
            }
        printf("%d\n", ans);
    }
    return 0;
}