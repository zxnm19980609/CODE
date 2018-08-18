#include <cstdio>
using namespace std;
const int MAXN = 5e5 + 10;
class Node {
public:
    char opt;
    int num;
}a[MAXN];
int n, t, trans[2][12];
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf(" %c %d ", &a[i].opt, &a[i].num);
    for (int k = 0; k < 10; ++k) {
        t = 0;
        for (int i = 1; i <= n; ++i) {
            switch (a[i].opt) {
                case '|': t |= a[i].num; break;
                case '^': t ^= a[i].num; break;
                case '&': t &= a[i].num; break;
            }
        }
        trans[0][k] = (t & (1 << k));

        t = (1 << k);
        for (int i = 1; i <= n; ++i) {
            switch (a[i].opt) {
                case '|': t |= a[i].num; break;
                case '^': t ^= a[i].num; break;
                case '&': t &= a[i].num; break;
            }
        }
        trans[1][k] = (t & (1 << k));
    }
    int ansOr = 0, ansAnd = 0, ansXor = 0;
    for (int k = 0; k < 10; ++k) {
        if (trans[0][k] && trans[1][k]) ansOr |= (1 << k);
        if (trans[0][k] && !trans[1][k]) ansXor |= (1 << k);
        if (!trans[0][k] && !trans[1][k])
            ;
        else
            ansAnd |= (1 << k);
    }
    printf("3\n");
    printf("& %d\n", ansAnd);
    printf("^ %d\n", ansXor);
    printf("| %d\n", ansOr);
    return 0;
}