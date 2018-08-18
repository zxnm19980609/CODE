#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 3005;
int n, m, p[MAX], c[MAX];
long long ans;
vector<int> v[MAX];
vector<int> tmpv;
long long solve(int k) {
    long long ret = 0LL;
    int sum = 0;
    for (int i = 2; i <= m; ++i)
        if ((int)v[i].size() >= k)
            sum += v[i].size() - k + 1;
    if ((int)v[1].size() + sum > k) return LLONG_MAX;
    tmpv.clear();
    sum = 0;
    for (int i = 2; i <= m; ++i)
        if ((int)v[i].size() >= k) {
            int lim = v[i].size() - k + 1;
            sum += lim;
            for (int j = 0; j < lim; ++j)
                ret += v[i][j];
            for (int j = lim; j < (int)v[i].size(); ++j)
                tmpv.push_back(v[i][j]);
        }
        else
            for (int j : v[i]) tmpv.push_back(j);
    int lim = k - v[1].size() - sum;
    if (lim > (int)tmpv.size()) return LLONG_MAX;
    sort(tmpv.begin(), tmpv.end());
    for (int i = 0; i < lim; ++i)
        ret += tmpv[i];
    return ret;
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &p[i], &c[i]);
        v[p[i]].push_back(c[i]);
    }
    for (int i = 2; i <= m; ++i)
        sort(v[i].begin(), v[i].end());
    long long ans = LLONG_MAX;
    for (int i = v[1].size(); i <= n; ++i)
        ans = min(ans, solve(i));
    printf("%I64d\n", ans);
    return 0;
}