#include <cstdio>
#include <stack>
#include <map>
using namespace std;
const int MAXN = 2e5 + 10;
int n, a[MAXN], dp[MAXN], pre[MAXN];
map<int, int> mp;
stack<int> stk;
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        dp[i] = 1;
    }
    mp.insert(make_pair(a[1], 1));
    map<int, int>::iterator mit;
    for (int i = 2; i <= n; ++i) {
        if ((mit = mp.find(a[i] - 1)) != mp.end()) {
            dp[i] = dp[mit->second] + 1;
            pre[i] = mit->second;
            if ((mit = mp.find(a[i])) != mp.end() && dp[i] > dp[mit->second])
                mp[mit->first] = i;
        }
        mp.insert(make_pair(a[i], i));
    }
    int mmax = -1, pos = -1;
    for (int i = 1; i <= n; ++i)
        if (mmax < dp[i]) {
            mmax = dp[i];
            pos = i;
        }
    printf("%d\n", mmax);
    stk.push(pos);
    while (pos = pre[pos])
        stk.push(pos);
    printf("%d", stk.top());
    stk.pop();
    while (!stk.empty()) {
        printf(" %d", stk.top());
        stk.pop();
    }
    printf("\n");
    return 0;
}