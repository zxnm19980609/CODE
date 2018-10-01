#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int n, m, a[MAXN];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int ans = 1;
    for (int i = 2; i <= n; ++i)
        if (a[i] - a[i - 1] > m) ++ans;
    printf("%d\n", ans);
    return 0;
}