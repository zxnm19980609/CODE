#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
const int MAXN = 1e5 + 5;
int n, d, k;
char name[MAXN][10];
PII c[MAXN];
int main() {
    scanf("%d%d%d", &n, &d, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%s%d", name[i], &c[i].first);
        c[i].second = i;
    }
    sort(c + 1, c + n + 1, [](PII a, PII b) {
        return a.first > b.first;
    });
    LL sum = 0;
    for (int i = 1; i <= k; ++i)
        sum += c[i].first;
    if (sum >= d) {
        printf("%d\n", k);
        for (int i = 1; i <= k; ++i)
            printf("%s, YOU ARE FIRED!\n", name[c[i].second]);
    }
    else
        puts("impossible");
    return 0;
}