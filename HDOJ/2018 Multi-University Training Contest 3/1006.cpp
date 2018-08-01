#include <cstdio>
using namespace std;
int main() {
    // freopen("in.txt", "r", stdin);
    int _, n, w, sum;
    for (scanf("%d", &_); _; --_) {
        sum = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &w);
            sum ^= w;
        }
        for (int i = 1; i < n; ++i)
            scanf("%*d%*d");
        if (sum)
            printf("Q\n");
        else
            printf("D\n");
    }
    return 0;
}