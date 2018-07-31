#include <cstdio>
using namespace std;
int main() {
    // freopen("in.txt", "r", stdin);
    int T, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &k);
        if (k == 1)
            printf("5\n");
        else
            printf("%d\n", k + 5);
    }
    return 0;
}