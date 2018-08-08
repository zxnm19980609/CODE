#include <cstdio>
using namespace std;
int main() {
    // freopen("in.txt", "r", stdin);
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int sum = 0;
        int m = n;
        for (int t, i = 1; i <= n; ++i) {
            scanf("%d", &t);
            if (t == 0) --m;
            sum += t;
        }
        if (sum - m < 100 && 100 <= sum)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}