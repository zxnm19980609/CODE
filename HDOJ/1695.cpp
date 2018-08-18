#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100010;
int mu[N + 5], prime[N + 5];
bool isprime[N + 5];
void Mobius() {
    memset(isprime, 1, sizeof isprime);
    int cnt = 0;
    mu[1] = 1;
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= N; ++i) {
        if (isprime[i]) {
            prime[++cnt] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= cnt && prime[j] * i <= N; ++j) {
            isprime[prime[j] * i] = false;
            if (i % prime[j] == 0)
                break;
            else
                mu[prime[j] * i] = -mu[i];
        }
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    Mobius();
    int n, m, a, b, c, d, k, T;
    scanf("%d", &T);
    for (int tcas = 1; tcas <= T; ++tcas) {
        printf("Case %d: ", tcas);
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        if (k == 0) {
            printf("0\n");
            continue;
        }
        n = b / k;
        m = d / k;
        if (n > m) swap(n, m);
        long long ans1 = 0, ans2 = 0;
        for (int i = 1; i <= n; ++i)
            ans1 = ans1 + (long long)mu[i] * (n / i) * (m / i);
        for (int i = 1; i <= n; ++i)
            ans2 = ans2 + (long long)mu[i] * (n / i) * (n / i);
        printf("%lld\n", ans1 - ans2 / 2);
    }
    return 0;
}