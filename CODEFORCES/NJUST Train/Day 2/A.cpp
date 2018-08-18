#include <cstdio>
using namespace std;
const int MAXN = 1e6 + 10;
int f[MAXN];
int main() {
    // freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    f[0] = f[1] = 1 % m;
    for (int i = 2; i <= n; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % m;
    printf("%d\n", f[n]);
    return 0;
}