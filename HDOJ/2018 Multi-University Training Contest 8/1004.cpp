#include <cstdio>
#include <algorithm>
using namespace std;
char s[210][210];
int h, w;
void print() {
    for (int i = 0; i < h; ++i) {
        s[i][w] = '\0';
        puts(s[i]);
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &h, &w);
        if ((h & 1) && (w & 1)) {
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j)
                    putchar('(');
                putchar('\n');
            }
        }
        else if (h & 1) {
            int c = w >> 1;
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < c; ++j)
                    putchar('(');
                for (int j = 0; j < c; ++j)
                    putchar(')');
                putchar('\n');
            }
        }
        else if (w & 1) {
            int c = h >> 1;
            for (int i = 0; i < c; ++i) {
                for (int j = 0; j < w; ++j)
                    putchar('(');
                putchar('\n');
            }
            for (int i = 0; i < c; ++i) {
                for (int j = 0; j < w; ++j)
                    putchar(')');
                putchar('\n');
            }
        }
        else {
            if (h + w - 4 > max(h, w) + (min(h, w) - 2) / 2) {
                for (int i = 1; i < h - 1; ++i) {
                    if (i & 1) {
                        for (int j = 1; j < w - 1; ++j)
                            if (j & 1)
                                s[i][j] = '(';
                            else
                                s[i][j] = ')';
                    }
                    else {
                        for (int j = 1; j < w - 1; ++j)
                            if (j & 1)
                                s[i][j] = ')';
                            else
                                s[i][j] = '(';
                    }
                }
                for (int i = 0; i < w; ++i) {
                    s[0][i] = '(';
                    s[h - 1][i] = ')';
                }
                for (int i = 0; i < h; ++i) {
                    s[i][0] = '(';
                    s[i][w - 1] = ')';
                }
                print();
            }
            else {
                bool flag = false;
                if (h > w) {
                    swap(h, w);
                    flag = true;
                }
                for (int i = 0; i < w; ++i) {
                    s[0][i] = '(';
                    s[h - 1][i] = ')';
                }
                for (int i = 1; i < h - 1; ++i) {
                    if (i & 1) {
                        for (int j = 0; j < w; ++j)
                            if (j & 1)
                                s[i][j] = ')';
                            else
                                s[i][j] = '(';
                    }
                    else {
                        for (int j = 0; j < w; ++j)
                            if (j & 1)
                                s[i][j] = '(';
                            else
                                s[i][j] = ')';
                    }
                }
                if (flag) {
                    for (int j = 0; j < w; ++j) {
                        for (int i = 0; i < h; ++i)
                            putchar(s[i][j]);
                        putchar('\n');
                    }
                }
                else
                    print();
            }
        }
    }
    return 0;
}