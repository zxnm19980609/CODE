#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int MAX = 15;
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
int k;
LL n, oriF[15], oriA[15];
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
    freopen("fibonacci.in", "r", stdin);
    freopen("fibonacci.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> k >> n;
    for (int i = 0; i < k; ++i)
        cin >> oriF[i];
    for (int i = 0; i < k; ++i)
        cin >> oriA[i];
    if (n < k) {
        LL sum = 0;
        for (int i = 0; i <= n; ++i)
            sum = (sum + oriF[i]) % MOD;
        cout << oriF[n] << ' ' << sum << endl;
        return 0;
    }
    Matrix F(1, k + 1);
    for (int i = 0; i < k; ++i) {
        F[0][k - i - 1] = oriF[i];
        F[0][k] = (F[0][k] + oriF[i]) % MOD;
    }
    Matrix A(k + 1, k + 1);
    for (int i = 0; i < k; ++i)
        A[i][0] = A[i][k] = oriA[i];
    A[k][k] = 1LL;
    for (int i = 0; i < k - 1; ++i)
        A[i][i + 1] = 1LL;
    A = fastPow(A, n - k + 1);
    F = F * A;
    cout << F[0][0] << ' ' << F[0][k] << endl;
    return 0;
}
