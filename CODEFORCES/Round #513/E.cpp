#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 1e5 + 5;
vector<int> edge[MAXN];
int n;
LL ans;
int dfs(int u) {
    int sum = 0;
    for (int v : edge[u]) {
        int t = dfs(v);
        ans += (LL)t * (n - t);
        ans -= (LL)(t - 1LL) * (n - t);
        ans -= (LL)sum * t;
        sum += t;
    }
    return sum + 1;
}
int main() {
    scanf("%d", &n);
    for (int u, v, i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
    }
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}