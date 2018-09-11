#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int n, num[MAXN];
char ch, s[MAXN];
int Abs(int x) {
    return x > 0 ? x : -x;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf(" %d %c ", &n, &ch);
        scanf("%s", s);
        for (int i = 0; i < n; ++i)
            num[i] = Abs(ch - s[i]);
        int ans = 0, p = -1;
        for (int i =0; i < n; ++i)
            if (num[i] != 0) {
                p = i;
                break;
            }
        if (~p) {
            int cnt = 0;
            while (num[p]) {
                ++cnt;
                num[p] /= 10;
            }
            ans = cnt + (n - p - 1) * 2;
        }
        else
            ans = 1;
        printf("%d\n", ans);
    }
    return 0;
}