#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, s, a[MAXN];
int main() {
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int mid = n >> 1;
    long long ans = 0LL;
    for (int i = 0; i <= mid; ++i)
        if (a[i] > s) ans += (long long)a[i] - s;
    for (int i = mid; i < n; ++i)
        if (a[i] < s) ans += (long long)s - a[i];
    printf("%I64d\n", ans);
    return 0;
}