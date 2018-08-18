#include <cstdio>
#include <algorithm>
using namespace std;
int a[1010];
int main() {
    // freopen("in.txt", "r", stdin);
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        int ans = -1;
        sort(a + 1, a + n + 1);
        for (int i = 2; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (a[i - 1] + a[i] > a[j])
                    ans = max(ans, a[i - 1] + a[i] + a[j]);
        printf("%d\n", ans);
    }
    return 0;
}