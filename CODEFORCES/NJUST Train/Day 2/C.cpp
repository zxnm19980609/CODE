#include <cstdio>
using namespace std;
int A[110][110], B[110][110], C[110][110];
int main() {
    // freopen("in.txt", "r", stdin);
    freopen("mmul.in", "r", stdin);
    freopen("mmul.out", "w", stdout);
    int p, q, r;
    scanf("%d%d%d", &p, &q, &r);
    for (int i = 0; i < p; ++i)
        for (int j = 0; j < q; ++j)
            scanf("%d", &A[i][j]);
    for (int i = 0; i < q; ++i)
        for (int j = 0; j < r; ++j)
            scanf("%d", &B[i][j]);
    for (int i = 0; i < p; ++i)
        for (int j = 0; j < r; ++j)
            for (int k = 0; k < q; ++k)
                C[i][j] += A[i][k] * B[k][j];
    for (int i = 0; i < p; ++i)
        for (int j = 0; j < r; ++j)
            printf(j == r - 1 ? "%d\n" : "%d ", C[i][j]);
        return 0;
}