#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    long long n, x, ans = 0;
    scanf("%lld", &n);
    while (n) {
        x = n % 10;
        n /= 10;
        if (n && x != 9) {
            x += 10;
            --n;
        }
        ans += x;
    }
    printf("%lld\n", ans);
    return 0;
}