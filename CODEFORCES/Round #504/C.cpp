#include <cstdio>
using namespace std;
const int L = 2e5 + 5;
char s[L];
int main() {
    // freopen("in.txt", "r", stdin);
    int n, k;
    scanf("%d%d%s", &n, &k, s);
    k >>= 1;
    int cntl, cntr;
    cntl = cntr = 0;
    for (int i = 0; s[i]; ++i) {
        if (cntl < k && s[i] == '(') {
            putchar(s[i]);
            ++cntl;
        }
        if (cntr < cntl && s[i] == ')') {
            putchar(s[i]);
            ++cntr;
        }
    }
    putchar('\n');
    return 0;
}