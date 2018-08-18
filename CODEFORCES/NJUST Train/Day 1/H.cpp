#include <cstdio>
#include <algorithm>
using namespace std;
int n;
char s[110];
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%s", &n, s);
    int ans = 0, sum = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == 'x')
            ++sum;
        else {
            ans += max(sum - 2, 0);
            sum = 0;
        }
    ans += max(sum - 2, 0);
    printf("%d\n", ans);
    return 0;
}