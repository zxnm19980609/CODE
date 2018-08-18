#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 2e5 + 10;
int n, k;
int a[MAXN];
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a, a + n);
    if (k == 0) {
        if (a[0] > 1)
            printf("1\n");
        else
            printf("-1\n");
    }
    else if (k != n && a[k - 1] == a[k])
        printf("-1\n");
    else
        printf("%d\n", a[k - 1]);
    return 0;
}