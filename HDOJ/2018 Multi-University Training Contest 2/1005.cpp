#include <cstdio>
using namespace std;
const int P = 47;
const int N = 2000;
char grid[N + 10][N + 10];
int main() {
    // freopen("in.txt", "r", stdin);
    printf("%d\n", N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            grid[i][j] = '0';
        grid[i][N] = '\0';
    }
    int x, y;
    for (int i = 0; i < P; ++i)
        for (int j = 0; j < P; ++j)
            for (int k = 0; k < P; ++k) {
                x = i * P + j;
                y = k * P + (i + j * k) % P;
                if (x < N && y < N) grid[x][y] = '1';
            }
    for (int i = 0; i < N; ++i)
        puts(grid[i]);
    return 0;
}