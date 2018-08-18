#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 2e5 + 10;
class Node {
public:
    int val, rank, id;
}a[MAXN];
int n, k, quarrels[MAXN], ans[MAXN];
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].val);
        a[i].id = i;
    }
    for (int x, y, i = 1; i <= k; ++i) {
        scanf("%d%d", &x, &y);
        if (a[x].val < a[y].val) ++quarrels[y];
        if (a[y].val < a[x].val) ++quarrels[x];
    }
    sort(a + 1, a + n + 1, [](const Node &a, const Node &b) {
        return a.val < b.val;
    });
    a[1].rank = 1;
    for (int i = 2; i <= n; ++i)
        if (a[i].val == a[i - 1].val)
            a[i].rank = a[i - 1].rank;
        else
            a[i].rank = i;
    for (int i = 1; i <= n; ++i)
        ans[a[i].id] = a[i].rank - 1 - quarrels[a[i].id];
    for (int i = 1; i <= n; ++i)
        printf(i == n ? "%d\n" : "%d ", ans[i]);
    return 0;
}
