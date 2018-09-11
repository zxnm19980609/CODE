#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL n;
int k;
char result[5];
void binarySearch(LL &l, LL &r) {
    LL m;
    while (r - l + 1 > 50) {
        m = (l + r) >> 1;
        printf("%I64d %I64d\n", l, m);
        fflush(stdout);
        scanf("%s", result);
        if (result[0] == 'Y') {
            l = max(l - k, 1LL);
            r = min(m + k, n);
        }
        else {
            l = max(m - k, 1LL);
            r = min(r + k, n);
        }
    }
}
int main() {
    scanf("%I64d%d", &n, &k);
    LL l = 1, r = n, m;
    binarySearch(l, r);
    srand(time(NULL));
    while (true) {
        LL pos = rand() % (r - l + 1) + l;
        printf("%I64d %I64d\n", pos, pos);
        fflush(stdout);
        scanf("%s", result);
        if (result[0] == 'Y')
            break;
        else {
            l = max(l - k, 1LL);
            r = min(r + k, n);
            binarySearch(l, r);
        }
    }
    return 0;
}