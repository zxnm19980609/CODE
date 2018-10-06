#include <bits/stdc++.h>
using namespace std;
char s[105];
int main() {
    int n, cnt = 0;
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; ++i)
        if (s[i] == '8') ++cnt;
    int ans = 0;
    while (ans + 1 <= cnt && 11 * (ans + 1) <= n) ++ans;
    printf("%d\n", ans);
    return 0;
}