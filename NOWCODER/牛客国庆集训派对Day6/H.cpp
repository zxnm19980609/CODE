#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m = INT_MIN;
    scanf("%d", &n);
    for (int t, i = 1; i <= n; ++i) {
        scanf("%d", &t);
        m = max(m, t);
    }
    printf("%d\n", m << 1);
    return 0;
}