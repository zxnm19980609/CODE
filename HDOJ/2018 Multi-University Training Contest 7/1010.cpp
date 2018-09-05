#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX = 5;
const LL MOD = 1e9 + 7;
class Matrix {
public:
    int r, c;
    LL mat[MAX][MAX];
    Matrix() {
        r = c = 0;
        memset(mat, 0, sizeof mat);
    }
    Matrix(int n) : r(n), c(n) {
        memset(mat, 0, sizeof mat);
    }
    Matrix(int r, int c) : r(r), c(c) {
        memset(mat, 0, sizeof mat);
    }
    LL* operator[](int r) {
        return mat[r];
    }
    Matrix operator*(Matrix b) {
        Matrix ret(r, b.c);
        for (int i = 0; i < r; ++i)
            for (int k = 0; k < c; ++k)
            for (int j = 0; j < b.c; ++j)
                ret[i][j] = (ret[i][j] + mat[i][k] * b[k][j]) % MOD;
        return ret;
    }
};
Matrix fastPow(Matrix a, LL b) {
    Matrix ret(a.r, a.c);
    for (int i = 0; i < ret.r; ++i)
        ret[i][i] = 1;
    while (b) {
        if (b & 1) ret = ret * a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}
int main() {
    // freopen("in.txt", "r", stdin);
    Matrix F(1, 3), coe(3, 3);
    LL a, b, c, d;
    int T, p, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld%lld%d%d", &a, &b, &c, &d, &p, &n);
        a %= MOD; b %= MOD; c %= MOD; d %= MOD;
        if (n < 3) {
            if (n == 1)
                printf("%lld\n", a);
            else
                printf("%lld\n", b);
            continue;
        }
        F[0][0] = b; F[0][1] = a; F[0][2] = 0;
        coe[0][0] = d; coe[0][1] = 1; coe[0][2] = 0;
        coe[1][0] = c; coe[1][1] = 0; coe[1][2] = 0;
        coe[2][0] = 1; coe[2][1] = 0; coe[2][2] = 1;
        int last = 0, lim = min(p, n);
        for (int i = 3; i <= lim; i = last + 1) {
            last = p / (p / i);
            F[0][2] = p / i;
            F = F * fastPow(coe, min(last - i + 1, lim - i + 1));
        }
        if (n > p) {
            F[0][2] = 0;
            F = F * fastPow(coe, n - max(p, 2));
        }
        printf("%lld\n", F[0][0]);
    }
    return 0;
}