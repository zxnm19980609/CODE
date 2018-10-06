#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Complex = complex<double>;
const int N = 200000;
const double PI = acos(-1.0);
Complex A[(N << 1) + 5];
LL zero, ind[N + 5], a[N + 5], b[N + 5], num[N + 5], ans[N + 5];
int n, m, p, pcn, prime[N + 5];
bool isprime[N + 5];
void init() {
    memset(isprime, 1, sizeof isprime);
    pcn = 0;
    for(int i = 2; i <= N; ++i) {
        if(isprime[i]) prime[pcn++] = i;
        for(int j = 0; j < pcn && prime[j] * i <= N; ++j){
            isprime[prime[j] * i] = false;
            if(i % prime[j] == 0) break;
        }
    }
}
LL quickPow(LL a, LL b, LL p) {
    LL ret = 1LL;
    while (b) {
        if (b & 1) ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}
LL getG(LL p) {
    if (p == 2) return 1;
    int n = p - 1, facts[200];
    int cnt = 0;
    for (int i = 0; i < pcn && prime[i] * prime[i] <= n; ++i) {
        if (n % prime[i] == 0)
            facts[cnt++] = prime[i];
        while (n % prime[i] == 0)
            n /= prime[i];
    }
    if (n > 1) facts[cnt++] = n;
    for (int g = 2; g < p; ++g) {
        bool flag = true;
        for (int i = 0; i < cnt && flag; ++i)
            flag = quickPow(g, (p - 1) / facts[i], p) != 1LL;
        if (flag) return g;
    }
    return -1;
}
void change(Complex y[], int len) {
    int i, j, k;
    for (i = 1, j = (len >> 1); i < len - 1; ++i) {
        if (i < j) swap(y[i], y[j]);
        k = len >> 1;
        while (j >= k) {
            j -= k;
            k >>= 1;
        }
        if (j < k) j += k;
    }
}
void fft(Complex y[], int len, int on) {
    change(y, len);
    for (int h = 2; h <= len; h <<= 1) {
        Complex wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
        for (int j = 0; j < len; j += h) {
            Complex w(1, 0);
            int h2 = h >> 1;
            for (int k = j; k < j + h2; ++k) {
                Complex u = y[k];
                Complex t = w * y[k + h2];
                y[k] = u + t;
                y[k + h2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1)
        for (int i = 0; i < len; ++i)
            y[i] /= len;
}
int main() {
    init();
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    int g = getG(p);
    int gp = 1, k = 0;
    do {
        ind[gp] = k++;
        gp = gp * g % p;
    } while (gp != 1);
    for (int i = 1; i <= n; ++i)
        if (a[i] % p)
            b[++m] = ind[a[i] % p];
        else
            ++zero;
    for (int i = 1; i <= m; ++i)
        ++num[b[i]];
    int len = 1;
    while (len < (p << 1)) len <<= 1;
    for (int i = 0; i < p; ++i)
        A[i] = Complex(num[i], 0);
    for (int i = p; i < len; ++i)
        A[i] = Complex(0, 0);
    fft(A, len, 1);
    for (int i = 0; i < len; ++i)
        A[i] *= A[i];
    fft(A, len, -1);
    memset(num, 0, sizeof num);
    for (int i = 0; i < len; ++i)
        num[i % (p - 1)] += LL(A[i].real() + 0.5);
    zero = 2*zero*(n-zero) + zero + zero*(zero-1);
    for (int i = 1; i <= n; ++i)
        if (a[i] >= p)
            puts("0");
        else if (a[i] % p)
            printf("%lld\n", num[ind[a[i] % p]]);
        else
            printf("%lld\n", zero);
    return 0;
}