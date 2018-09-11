#include <bits/stdc++.h>
using namespace std;
int n, a, b, clr[25];
int main() {
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &clr[i]);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (clr[i] != 2 && clr[n - i + 1] != 2 && clr[i] != clr[n - i + 1]) {
            puts("-1");
            return 0;
        }
        else if (clr[i] == 2 && clr[n - i + 1] == 2)
            ans += min(a, b);
        else if (clr[i] == 2 && clr[n - i + 1] == 0)
            ans += a;
        else if (clr[i] == 2 && clr[n - i + 1] == 1)
            ans += b;
    printf("%d\n", ans);
    return 0;
}