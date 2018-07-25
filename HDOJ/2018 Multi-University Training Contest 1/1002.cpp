#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
const int MAXL = 1e5 + 10;
const int MAXN = 1e5 + 10;
int ans, n;
char str[MAXL];
pair<int, int> a[MAXN];
stack<char> stk;
bool cmp(pair<int, int> a, pair<int, int> b) {
    int ab = min(a.second, b.first);
    int ba = min(b.second, a.first);
    return ab > ba || (ab == ba && b.second - a.first > a.second - b.first);
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%s", str);
            int cntl = 0, cntr = 0;
            while(!stk.empty()) stk.pop();
            for (int j = 0; str[j]; ++j) {
                if (str[j] == '(') {
                    ++cntl;
                    stk.push('(');
                }
                else {
                    ++cntr;
                    if (!stk.empty() && stk.top() == '(') {
                        stk.pop();
                        --cntl;
                        --cntr;
                        ++ans;
                    }
                }
            }
            a[i].first = cntr;
            a[i].second = cntl;
        }
        sort(a, a + n, cmp);
        for (int cntl = 0, cntr = 0, match, i = 0; i < n; ++i) {
            match = min(cntl, a[i].first);
            ans += match;
            cntl += a[i].second - match;
            cntr += a[i].first - match;
        }
        printf("%d\n", ans << 1);
    }
    return 0;
}
