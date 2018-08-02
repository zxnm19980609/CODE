#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 1e5 + 10;
int n, w[MAXN];
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &w[i]);
        printf("%d\n", (int)sqrt(abs(w[1] - w[n])));
    }
    return 0;
}