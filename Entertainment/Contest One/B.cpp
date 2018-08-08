#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char chocolate[50];
int k, n, m;
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &k, &n, &m);
    int mars = 0;
    for (int i = 0; i < k; ++i) {
        scanf("%s", chocolate);
        if (strcmp(chocolate, "Mars") == 0) ++mars;
    }
    if (k - mars >= m)
        printf("%d\n", max(0, n + m - k));
    else
        printf("%d\n", m - k + mars + max(0, n - mars));
    return 0;
}