#include <cstdio>
using namespace std;
const int MAXL = 1e5 + 5;
int n, cnt[30];
char s[MAXL];
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%s", &n, s);
    if (n == 1) {
        puts("Yes");
        return 0;
    }
    for (int i = 0; i < n; ++i)
        ++cnt[s[i] - 'a'];
    for (int i = 0; i < 26; ++i)
        if (cnt[i] >= 2) {
            puts("Yes");
            return 0;
        }
    puts("No");
    return 0;
}