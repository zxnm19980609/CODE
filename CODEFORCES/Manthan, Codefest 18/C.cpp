#include <bits/stdc++.h>
using namespace std;
const int MAXL = 1e6 + 5;
char a[MAXL], b[MAXL];
int main() {
    int n;
    scanf("%d%s%s", &n, a, b);
    int ans = 0;
    for (int i = 1; i < n; ++i)
        if (a[i - 1] == '0' && a[i] == '1' &&
            b[i - 1] == '1' && b[i] == '0') {
            a[i - 1] = '1';
            a[i] = '0';
            ++ans;
        }
        else if (a[i - 1] == '1' && a[i] == '0' &&
                 b[i - 1] == '0' && b[i] == '1') {
            a[i - 1] = '0';
            a[i] = '1';
            ++ans;
        }
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i]) ++ans;
    printf("%d\n", ans);
    return 0;
}