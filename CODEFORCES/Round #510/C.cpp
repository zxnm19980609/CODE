#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
class Node {
public:
    int val, id;
}a[MAXN];
int n;
bool vis[MAXN];
int main() {
    scanf("%d", &n);
    int eq0 = 0, lt0 = 0, gt0 = 0;
    int mmin = INT_MAX, mid = -1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].val);
        a[i].id = i;
        if (a[i].val > 0)
            ++gt0;
        else if (a[i].val < 0)
            ++lt0;
        else
            ++eq0;
    }
    sort(a + 1, a + n + 1, [](const Node &a, const Node &b) {
        return a.val < b.val;
    });
    int pos = -1;
    for (int i = 1; i <= n; ++i)
        if (a[i].val >= 0) {
            pos = i - 1;
            break;
        }
    return 0;
}