#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int n, m, q, x[MAXN];
int stMin[MAXN][31], stMax[MAXN][31];
stack<pair<int, int>> stk;
void init(int n) {
    for(int j = 1; (1 << j) < n; ++j)
        for(int i = 0; i + (1 << j) - 1 < n; ++i) {
            stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
            stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
        }
}
int queryMax(int l, int r) {
	int k = floor(log2(r - l + 1));
    return max(stMax[l][k], stMax[r - (1 << k) + 1][k]);
}
int queryMin(int l, int r) {
	int k = floor(log2(r - l + 1));
    return min(stMin[l][k], stMin[r - (1 << k) + 1][k]);
}
int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);
    for (int i = 1; i <= n; ++i) {
        stMax[i][0] = n + 1;
        stMin[i][0] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (x[i] & 1) {
            if (!stk.empty()) {
                pair<int, int> tp = stk.top();
                if (tp.first == (x[i] >> 1)) {
                    stMax[tp.second][0] = i;
                    stMin[tp.second][0] = i;
                    stMax[i][0] = tp.second;
                    stMin[i][0] = tp.second;
                    stk.pop();
                }
            }
        }
        else
            stk.push(make_pair(x[i] >> 1, i));
    }
    init(n);
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (queryMax(l, r) <= r && queryMin(l, r) >= l)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}