#include <cstdio>
using namespace std;
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    long long n;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        if (n % 3 == 0)
            printf("%lld\n", n * n * n / 27);
        else if (n % 4 == 0)
            printf("%lld\n", n * n * n / 32);
        else
            printf("-1\n");
    }
    return 0;
}
