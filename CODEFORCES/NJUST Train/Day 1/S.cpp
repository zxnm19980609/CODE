#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int n, d, a[110];
set<int> loc;
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    loc.insert(a[1] - d);
    loc.insert(a[n] + d);
    if (a[2] - (a[1] + d) >= d) loc.insert(a[1] + d);
    if ((a[n] - d) - a[n - 1] >= d) loc.insert(a[n] - d);
    for (int i = 2; i < n; ++i) {
        if (a[i + 1] - (a[i] + d) >= d) loc.insert(a[i] + d);
        if ((a[i] - d) - a[i - 1] >= d) loc.insert(a[i] - d);
    }
    printf("%d\n", (int)loc.size());
    return 0;
}