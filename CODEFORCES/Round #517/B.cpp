#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
int n, k, dp[MAXN][MAXN];
char mmin, mat[MAXN][MAXN], ans[MAXN << 1];
vector<pair<int, int>> *pts, *tmp;
int main() {
    // freopen("in.txt", "r", stdin);
    pts = new vector<pair<int, int>>;
    tmp = new vector<pair<int, int>>;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%s", mat[i] + 1);
    dp[1][1] = mat[1][1] == 'a' ? 0 : 1;
    for (int i = 2; i <= n; ++i) {
        dp[1][i] = dp[1][i - 1] + (mat[1][i] == 'a' ? 0 : 1);
        dp[i][1] = dp[i - 1][1] + (mat[i][1] == 'a' ? 0 : 1);
    }
    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= n; ++j)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + (mat[i][j] == 'a' ? 0 : 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (dp[i][j] <= k) mat[i][j] = 'a';
    ans[1] = mat[1][1];
    pts->push_back(make_pair(1, 1));
    int p = 2;
    while (p < 2 * n) {
        mmin = 'z';
        for (auto &pt : *pts) {
            if (pt.first + 1 <= n)
                mmin = min(mmin, mat[pt.first + 1][pt.second]);
            if (pt.second + 1 <= n)
                mmin = min(mmin, mat[pt.first][pt.second + 1]);
        }
        ans[p++] = mmin;
        tmp->clear();
        for (auto &pt : *pts) {
            if (pt.first + 1 <= n && mat[pt.first + 1][pt.second] == mmin)
                tmp->push_back(make_pair(pt.first + 1, pt.second));
            if (pt.second + 1 <= n && mat[pt.first][pt.second + 1] == mmin)
                tmp->push_back(make_pair(pt.first, pt.second + 1));
        }
        swap(pts, tmp);
        sort(pts->begin(), pts->end());
        pts->erase(unique(pts->begin(), pts->end()), pts->end());
    }
    ans[p] = '\0';
    puts(ans + 1);
    return 0;
}