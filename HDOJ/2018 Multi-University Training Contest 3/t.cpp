#include <cstdio>
using namespace std;
int main() {
    freopen("in.txt", "r", stdin);
    int am, ac;
    am = 0, ac = 0;
    int n;
    scanf("%d", &n);
    for (int r, c, i = 1; i <= n; ++i) {
        scanf("%d%d", &r, &c);
       am += r ^ i;
        ac += c ^ i;
    }
    printf("%d %d\n", am, ac);
    return 0;
}