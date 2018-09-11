#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2e5 + 5;
int n, x[MAXN], tr[MAXN];
LL a[MAXN], b[MAXN], t;
inline int lowbit(int x) {
    return x & (-x);
}
void update(int x, int c) {
    while(x <= n) {
        tr[x] += c;
        x += lowbit(x);
    }
}
int query(int x) {
    int ret = 0;
    while (x) {
        ret += tr[x];
        x -= lowbit(x);
    }
    return ret;
}
int main() {
    scanf("%d%I64d", &n, &t);
    for (int i = 1; i <= n; ++i)
        scanf("%I64d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);
    bool flag = true;
    for (int i = 1; i <= n; ++i)
        if (x[i] < i || x[i] < x[i - 1]) {
            flag = false;
            break;
        }
    if (!flag) {
        puts("No");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        update(i, 1);
    for (int i = 1; i <= n; ++i)
        if (x[i] > i) {
            update(i, 1);
            update(x[i], -1);
        }
    for (int i = 1; i <= n; ++i) {
        b[i]
    }
    puts("Yes");
    for (int i = 1; i <= n; ++i)
        printf("%I64d ", a[query(i)] + t);
    return 0;
}