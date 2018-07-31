#include <cstdio>
using namespace std;
char cube[1010][1010];
int main() {
    // freopen("in.txt", "r", stdin);
    int T, a, b, c;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &a, &b, &c);
        int n = 2 * (b + c) + 1;
        int m = 2 * (b + a) + 1;
        int dot = b << 1;


        for (int i = 0; dot; ++i) {
            for (int j = 0; j < dot; ++j)
                cube[i][j] = '.';
            --dot;
        }
        dot = b << 1;
        for (int i = n - 1; dot; --i) {
            for (int j = 0; j < dot; ++j)
                cube[i][m - j - 1] = '.';
            --dot;
        }


        dot = b << 1;
        for (int j = dot; j < m; ++j)
            if ((j & 1) == (dot & 1))
                cube[0][j] = '+';
            else
                cube[0][j] = '-';
        --dot;


        int ii, cnt;
        for (ii = 1, cnt = 0; cnt < b; ++cnt) {
            for (int j = dot; j < m - ii; ++j)
                if ((j & 1) == (dot & 1))
                    cube[ii][j] = '/';
                else
                    cube[ii][j] = '.';
            --dot;
            ++ii;
            for (int j = dot; j < m - ii; ++j)
                if ((j & 1) == (dot & 1))
                    cube[ii][j] = '+';
                else
                    cube[ii][j] = '-';
            --dot;
            ++ii;
        }

        for (ii; ii < n;) {
            for (int j = 0; j <= (a << 1); ++j)
                if (j & 1)
                    cube[ii][j] = '.';
                else
                    cube[ii][j] = '|';
            ++ii;
            for (int j = 0; j <= (a << 1); ++j)
                if (j & 1)
                    cube[ii][j] = '-';
                else
                    cube[ii][j] = '+';
            ++ii;
        }


        for (int i = b << 1; i < n - 1;) {
            int ti = i;
            for (int j = (a << 1) + 1; j < m; --ti, ++j)
                if (j & 1)
                    cube[ti][j] = '.';
                else
                    cube[ti][j] = '|';
            ++i;
            ti = i;
            for (int j = (a << 1) + 1; j < m; --ti, ++j)
                if (j & 1)
                    cube[ti][j] = '/';
                else
                    cube[ti][j] = '+';
            ++i;
        }


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                putchar(cube[i][j]);
            putchar('\n');
        }
    }
    return 0;
}