#include <cstdio>
#include <stack>
using namespace std;
int n, a[55];
bool vis[1010];
stack<int> stk;
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = n; i; --i)
        if (!vis[a[i]]) {
            stk.push(a[i]);
            vis[a[i]] = true;
        }
    printf("%d\n", stk.size());
    printf("%d", stk.top());
    stk.pop();
    while (!stk.empty()) {
        printf(" %d", stk.top());
        stk.pop();
    }
    printf("\n");
    return 0;
}