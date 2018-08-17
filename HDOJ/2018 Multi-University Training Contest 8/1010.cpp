#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 5;
int n, m, a[MAXN];
bool selected[MAXN];
int ans[MAXN], num[MAXN], idx[MAXN], c;
vector<int> v[MAXN];
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            v[i].clear();
        }
        memset(selected, 0, sizeof selected);
        c = 1;
        ans[0] = 1;
        num[0] = a[0];
        idx[0] = 0;
        selected[1] = true;
        for (int i = 1; i < n; ++i) {
            if (a[i] > num[c - 1]) {
                num[c] = a[i];
                idx[c] = i;
                selected[i] = true;
                c++;
            }
            else if (v[idx[c - 1]].empty() || a[i] > *v[idx[c - 1]].rbegin())
                v[idx[c - 1]].push_back(a[i]);
            ans[i] = c;
        }
        while (m--) {
            int p, q;
            scanf("%d%d", &p, &q);
            if (!selected[p]) {
                if (q <= a[p])
                    printf("%d\n", c);
                else {
                    if (p > idx[c - 1]) {
                        if (q > num[c - 1])
                            printf("%d\n", c + 1);
                        else
                            printf("%d\n", c);
                    }
                    else {
                        int start = upper_bound(idx, idx + c, p) - idx;
                        int x = num + c - upper_bound(num + start, num + c, q);
                        if (q > num[start - 1]) ++x;
                        printf("%d\n", ans[p] + x);
                    }
                }
            }
            else {
                if (q >= a[p]) {
                    int start = upper_bound(idx, idx + c, p) - idx;
                    int x = num + c - upper_bound(num + start, num + c, q);
                    printf("%d\n", ans[p] + x);
                }
                else {
                    int liml, limr;
                    int idxp = lower_bound(idx, idx + c, p) - idx;
                    if (idxp == 0)
                        liml = q;
                    else
                        liml = max(q, num[idxp - 1]);
                    if (idxp == c - 1)
                        limr = INT_MAX;
                    else
                        limr = num[idxp + 1];
                    int x = (upper_bound(v[p].begin(), v[p].end(), limr) - upper_bound(v[p].begin(), v[p].end(), liml));
                    if (idxp == 0 || q > num[idxp - 1])
                        printf("%d\n", ans[p] + x);
                    else
                        printf("%d\n", ans[p] + x - 1);
                }
            }
        }
    }
    return 0;
}