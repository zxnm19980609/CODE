#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
int n, cnt[MAXN];
char str[MAXN];
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%s", str + 1);
    cnt[1] = 1;
    for (int i = 2; i <= n; ++i)
        if (str[i] == str[i - 1])
            cnt[i] = cnt[i - 1] + 1;
        else
            cnt[i] = 1;
    int mmax = -1;
    for (int i = 1; i <= n; ++i)
        mmax = max(mmax, cnt[i]);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (cnt[i] == mmax) ++ans;
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i)
        if (cnt[i] == mmax) {
            for (int j = i - cnt[i] + 1; j <= i; ++j)
                putchar(str[i]);
            putchar('\n');
        }
    return 0;
}