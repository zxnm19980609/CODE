#include <cstdio>
#include <algorithm>
using namespace std;
int hr[25];
int main() {
    // freopen("in.txt", "r", stdin);
    int n, l, r;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &l, &r);
        for (int i = l; i < r; ++i)
            ++hr[i];
    }
    int mmax = -1;
    for (int i = 0; i < 25; ++i)
        mmax = max(mmax, hr[i]);
    printf("%d\n", mmax);
    return 0;
}