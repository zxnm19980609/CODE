#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        long long n, a, b, c;
        scanf("%lld%lld", &n, &a);
        if (n > 2 || n == 0)
            puts("-1 -1");
        else if (n == 1)
            printf("1 %lld\n", a + 1);
        else {
            if (a & 1) {
                long long m = a >> 1;
                b = 2 * m * m + 2 * m;
                c = b + 1;
                if (c > 1000000000LL)
                    puts("-1 -1");
                else
                    printf("%lld %lld\n", b, c);
            }
            else {
                long long m = a >> 1;
                b = m * m - 1;
                c = m * m + 1;
                if (c > 1000000000LL)
                    puts("-1 -1");
                else
                    printf("%lld %lld\n", b, c);
            }
        }
    }
    return 0;
}