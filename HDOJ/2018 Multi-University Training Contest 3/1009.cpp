#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAX = 100;
const int MOD = 1e9 + 7;
int n, m, a[MAX + 5], l[MAX + 5], r[MAX + 5];
int gcd[MAX + 5][MAX + 5];
LL v[MAX + 5], dp[2][MAX + 5][MAX + 5][MAX + 5];
vector<int> factors[MAX + 5];
void init() {
    for (int i = 1; i <= MAX; ++i)
        for (int j = 1; j <= MAX; ++j)
            gcd[i][j] = __gcd(i, j);
    for (int i = 1; i <= MAX; ++i)
        for (int j = i; j <= MAX; j += i)
            factors[j].push_back(i);
}
LL quickPow(LL a, LL b) {
    LL t = 1, y = a;
    while (b) {
        if (b & 1) t = t * y % MOD;
        y = y * y % MOD;
        b >>= 1;
    }
    return t;
}
int main() {
    // freopen("in.txt", "r", stdin);
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i<= n; ++i) {
            scanf("%d", &a[i]);
            if (a[i])
                l[i] = r[i] = a[i];
            else {
                l[i] = 1;
                r[i] = m;
            }
        }
        for (int i = 1; i <= m; ++i)
            scanf("%lld", &v[i]);
        memset(dp, 0, sizeof dp);
        int f = 0;
        for (int i = l[3]; i <= r[3]; ++i)
            for (int j = l[2]; j <= r[2]; ++j)
                for (int k = l[1]; k <= r[1]; ++k)
                    ++dp[f][i][gcd[i][j]][gcd[gcd[i][j]][k]];
        for (int i = 3; i < n; ++i) {
            for (int x = 1; x <= m; ++x)
                for (int y : factors[x])
                    for (int z : factors[y]) {
                        if (z > m) break;
                        if (!dp[f][x][y][z]) continue;
                        for (int j = l[i + 1]; j <= r[i + 1]; ++j) {
                            dp[f ^ 1][j][gcd[j][x]][gcd[j][y]] += dp[f][x][y][z] * v[gcd[j][z]] % MOD;
                            dp[f ^ 1][j][gcd[j][x]][gcd[j][y]] %= MOD;
                        }
                        dp[f][x][y][z] = 0;
                    }
            f ^= 1;
        }
        LL ans = 0;
        for (int x = 1; x <= m; ++x)
            for (int y : factors[x])
                for (int z : factors[y])
                    ans = (ans + dp[f][x][y][z]) % MOD;
        LL invm = quickPow(m, MOD - 2);
        for (int i = 1; i <= n; ++i)
            if (!a[i]) ans = ans * invm % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}