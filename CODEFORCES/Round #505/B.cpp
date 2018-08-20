#include <bits/stdc++.h>
using namespace std;
const int MAXN = 150005;
int n;
pair<int, int> a[MAXN];
bool check(int x) {
    for (int i = 0; i < n; ++i)
        if (a[i].first % x != 0 && a[i].second % x != 0)
            return false;
    return true;
}
bool checkA0(int x) {
    int lim = (int)floor(sqrt(x));
    for (int i = 2; i <= lim; ++i)
        if (x % i == 0) {
            while (x % i == 0)
                x /= i;
            if (check(i)) {
                printf("%d\n", i);
                exit(0);
            }
        }
    if (x > 1 && check(x)) {
        printf("%d\n", x);
        exit(0);
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &a[i].first, &a[i].second);
    checkA0(a[0].first);
    checkA0(a[0].second);
    puts("-1");
    return 0;
}