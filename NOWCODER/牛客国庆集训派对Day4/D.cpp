#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 +5;
int a[MAXN];
int main() {
    int n;
    scanf("%d", &n);
    int mmin = INT_MAX, pos = -1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] < mmin) {
            mmin = a[i];
            pos = i;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
        if (i == pos)
            ans += (long long)a[i] * (n - 1LL);
        else
            ans += a[i];
    printf("%lld\n", ans);
    return 0;
}