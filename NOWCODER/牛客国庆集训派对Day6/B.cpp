#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 1005;
int n, mat[MAXN][MAXN];
LL sum, dig;
int main() {
    scanf("%d", &n);
    assert(n != 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &mat[i][j]);
            sum += mat[i][j] == -1 ? 0 : mat[i][j];
        }
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        dig += mat[i][i] == -1 ? 0 : mat[i][i];
        flag |= mat[i][i] == -1;
    }
    if (flag)
        printf("%lld\n", (sum - n * dig) / (n - 1));
    else
        printf("%lld\n", n * dig - sum);
    return 0;
}