#include <bits/stdc++.h>
using namespace std;
char s[110];
bool check(int n) {
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] == s[n - i - 1]) continue;
        if (abs(s[i] - s[n - i - 1]) != 2) return false;
    }
    return true;
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &n, s);
        if (check(n))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}