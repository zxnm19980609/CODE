#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-4;
int n, m, k, a, b;
bool solve1() {
    int g = __gcd(n * 2, k);
    a = n / g;
    b = m / (k / g);
    if (a <= n && b <= m) {
        printf("YES\n0 0\n%d 0\n0 %d\n", a, b);
        return true;
    }
    else
        return false;
}
bool solve2() {
    int g = __gcd(m * 2, k);
    a = n / (k / g);
    b = m / g;
    if (a <= n && b <= m) {
        printf("YES\n0 0\n%d 0\n0 %d\n", a, b);
        return true;
    }
    else
        return false;
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    double s = (double)n * m / (double)k;
    double e = s - floor(s);
    if (fabs(e) <= EPS) {
        int g = __gcd(n, k);
        if (g >= 2) {
            a = n / g * 2;
            b = m / (k / g);
        }
        else {
            a = n / g;
            b = m / (k / g) * 2;
        }
        printf("YES\n0 0\n%d 0\n0 %d\n", a, b);
    }
    else if (fabs(e - 0.5) <= EPS) {
        if (solve1())
            ;
        else if (solve2())
            ;
        else
            puts("NO");
    }
    else {
        puts("NO");
    }
    return 0;
}