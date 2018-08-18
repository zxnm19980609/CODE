#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    // freopen("in.txt", "r", stdin);
    int a, b;
    scanf("%d%d", &a, &b);
    int n, m, p, q;
    for(int i = 1; i < a; ++i) {
        int c = sqrt(a * a - i * i);
        if(c * c + i * i == a * a) {
            m = i;
            n = c;
            for(int j = 1; j < b; ++j) {
                c = sqrt(b * b - j * j);
                if(c * c + j * j == b * b) {
                    p = j;
                    q = c;
                    if(n * p - m * q == 0 && n != p) {
                        printf("YES\n%d %d\n%d %d\n0 0\n", -m, n, q, p);
                        return 0;
                    }
                    else if(n * q - m * p == 0 && n != q) {
                        printf("YES\n%d %d\n%d %d\n0 0\n", -m, n, p, q);
                        return 0;
                    }
                }
            }
        }
    }
    puts("NO");
    return 0;
}