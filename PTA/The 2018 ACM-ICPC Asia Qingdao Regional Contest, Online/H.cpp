#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 1e5 + 5;
int n;
LL st0[MAXN], st1[MAXN], sum0[MAXN], sum1[MAXN];
char s[MAXN];
bool lights[MAXN];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        for (int i = 1; i <= n; ++i)
            lights[i] = (s[i] == '1');
        st0[0] = 0;
        st1[1] = 0;
        int tim = 0;
        for (int i = 1; i <= n; ++i)
            if (tim & 1) {
                if (lights[i])
                    st0[i] = ++tim;
                else
                    st0[i] = (tim += 2);
            }
            else {
                if (lights[i])
                    st0[i] = (tim += 2);
                else
                    st0[i] = ++tim;
            }
        tim = 0;
        for (int i = 2; i <= n; ++i)
            if (tim & 1) {
                if (lights[i])
                    st1[i] = ++tim;
                else
                    st1[i] = (tim += 2);
            }
            else {
                if (lights[i])
                    st1[i] = (tim += 2);
                else
                    st1[i] = ++tim;
            }
        sum0[n] = st0[n];
        for (int i = n - 1; ~i; --i)
            sum0[i] = sum0[i + 1] + st0[i];
        sum1[n] = st1[n];
        for (int i = n - 1; i; --i)
            sum1[i] = sum1[i + 1] + st1[i];
        LL ans = 0;
        for (int p = 0; p < n; p += 2)
            ans += st0[p + 1] - (LL)(n - p) * st0[p];
        for (int p = 1; p < n; p += 2)
            ans += st1[p + 1] - (LL)(n - p) * st1[p];
        printf("%lld\n", ans);
    }
    return 0;
}