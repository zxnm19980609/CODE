#include <cstdio>
using namespace std;
char s[10][10], opt[10];
int main() {
    // freopen("in.txt", "r", stdin);
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < 3; ++i)
            scanf(" %s ", s[i]);
        while (n--) {
            scanf(" %s ", opt);
            int r1, r2, c1, c2;
            switch (opt[0]) {
                case '1':
                    r1 = 0; r2 = 1;
                    c1 = 0; c2 = 1;
                    break;
                case '2':
                    r1 = 0; r2 = 1;
                    c1 = 1; c2 = 2;
                    break;
                case '3':
                    r1 = 1; r2 = 2;
                    c1 = 0; c2 = 1;
                    break;
                case '4':
                    r1 = 1; r2 = 2;
                    c1 = 1; c2 = 2;
                    break;
            }
            if (opt[1] == 'C') {
                char tmp = s[r1][c1];
                s[r1][c1] = s[r2][c1];
                s[r2][c1] = s[r2][c2];
                s[r2][c2] = s[r1][c2];
                s[r1][c2] = tmp;
            }
            else {
                char tmp = s[r1][c1];
                s[r1][c1] = s[r1][c2];
                s[r1][c2] = s[r2][c2];
                s[r2][c2] = s[r2][c1];
                s[r2][c1] = tmp;
            }
        }
        for (int i = 0; i < 3; ++i)
            printf("%s\n", s[i]);
    }
    return 0;
}