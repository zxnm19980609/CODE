#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
int n, x, y;
long long ans;
int a[MAXN], tmp[MAXN];
void Merge(int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = l;
    while (i <= m && j <= r) {
        if (a[i] > a[j]) {
            tmp[k++] = a[j++];
            ans += m - i + 1;
        }
        else
            tmp[k++] = a[i++];
    }
    while (i <= m) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int fi = l; fi <= r; ++fi)
        a[fi] = tmp[fi];
}
void mergeSort(int l, int r) {
    if (l < r) {
        int m = (l + r) >> 1;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        Merge(l, m, r);
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d%d%d", &n, &x, &y)) {
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        ans = 0;
        mergeSort(0, n - 1);
        printf("%lld\n", ans * min(x, y));
    }
    return 0;
}