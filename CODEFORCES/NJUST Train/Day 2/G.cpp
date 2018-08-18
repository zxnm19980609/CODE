#include <cstdio>
#include <stack>
using namespace std;
const int MAXN = 1010;
const int MAXM = 10010;
int n, m, dp[MAXM], v[MAXN], c[MAXN];
bool f[MAXN][MAXM];
stack<int> stk;
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &v[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= v[i]; --j)
            if (dp[j] < dp[j - v[i]] + c[i]) {
                dp[j] = dp[j - v[i]] + c[i];
                f[i][j] = true;
            }
    for(int i = n, j = m; i && j; --i)
        if(f[i][j]) {
            stk.push(i);
            j -= v[i];
        }
    printf("%d\n", (int)stk.size());
    while (!stk.empty()) {
        printf("%d ", stk.top());
        stk.pop();
    }
    putchar('\n');
    return 0;
}