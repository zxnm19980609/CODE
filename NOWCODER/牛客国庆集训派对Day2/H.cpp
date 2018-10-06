#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    for (int tcas = 1; tcas <= T; ++tcas) {
        printf("Case #%d: ", tcas);
        int k;
        double a, b, ans = 0;
        scanf("%lf%lf%d", &a, &b, &k);
        while (k--) {
            ans += a / b;
            a -= 1.0;
            b -= 1.0;
        }
        printf("%.8f\n", ans);
    }
    return 0;
}