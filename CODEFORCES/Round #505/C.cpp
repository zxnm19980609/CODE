#include <bits/stdc++.h>
using namespace std;
const int MAXL = 2e5 + 5;
char s[MAXL];
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; ++i)
        s[i + len] = s[i];
    int ans = 0;
    for (int i = 0, j = 0; i < len; ++i) {
        if (j < i) j = i;
        while (j + 1 - i + 1 <= len && s[j + 1] != s[j]) ++j;
        ans = max(ans, j - i + 1);
    }
    printf("%d\n", ans);
    return 0;
}