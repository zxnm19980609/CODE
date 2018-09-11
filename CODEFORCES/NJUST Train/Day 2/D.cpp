#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
const int MAX = 150;
LL MOD;
int n;
LL m, p;
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
    freopen("mpow.in", "r", stdin);
    freopen("mpow.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> p;
    Matrix A(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];
    MOD = p;
    A = fastPow(A, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << A[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
