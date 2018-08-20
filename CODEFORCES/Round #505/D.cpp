#include <bits/stdc++.h>
using namespace std;
int n, a[705];
bool check(int i) {
    for (int j = 1; j <= n; ++j)
        if (j != i && __gcd(a[i], a[j]) != 1) return true;
    return false;
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        if (!check(i)) {
            puts("No");
            return 0;
        }
    puts("Yes");
    return 0;
}