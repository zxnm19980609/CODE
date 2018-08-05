#include <cstdio>
using namespace std;
const int MAXN = 1e5 + 5;
int n, q, cnt[26][MAXN];
char str[MAXN];
int main() {
    int T;
    scanf("%d", &T);
    for (int tcase = 1; tcase <= T; ++tcase) {
        printf("Case #%d:\n", tcase);
        scanf("%d%d%s", &n, &q, str + 1);
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < 26; ++j)
                cnt[j][i] = cnt[j][i - 1] + (j == str[i] - 'A');
        while (q--) {
            int l, r, ans;
            scanf("%d%d", &l, &r);
            for (int i = 0; i < 26; ++i)
                if ((ans = cnt[i][r] - cnt[i][l - 1]) != 0) {
                    printf("%d\n", ans);
                    break;
                }
        }
    }
    return 0;
}