#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 3e5 + 5;
int n, m;
LL a[MAXN], b[MAXN], ans[MAXN];
int main() {
    scanf("%d", &n);
    LL suma = 0, sumb = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d", &a[i]);
        suma += a[i];
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%I64d", &b[i]);
        sumb += b[i];
    }
    if (suma != sumb) {
        puts("-1");
        return 0;
    }
    int cnt = 0, pa = 1, pb = 1;
    LL sa = 0, sb = 0;
    while (pa <= n && pb <= m) {
        if (sa && sb && sa == sb) {
            ans[cnt++] = sa;
            sa = sb = 0;
        }
        if (!sa) sa += a[pa++];
        if (!sb) sb += b[pb++];
        if (sa < sb)
            sa += a[pa++];
        else if (sa > sb)
            sb += b[pb++];
    }
    while (pa <= n) sa += a[pa++];
    while (pb <= m) sb += b[pb++];
    if (sa && sb && sa == sb) {
        ans[cnt++] = sa;
        sa = sb = 0;
    }
    printf("%d\n", cnt);
    return 0;
}