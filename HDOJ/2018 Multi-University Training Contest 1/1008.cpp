#include <cstdio>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
class CartesianTree {
public:
    int left, right, value, id;
    bool operator<(const CartesianTree &obj) const {
        return value < obj.value || (value == obj.value && id > obj.id);
    }
}tree[MAXN];
LL ans, inv[MAXN];
int n, top, stk[MAXN];
void init() {
    inv[1] = 1;
    for (int i = 2; i < MAXN; ++i)
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
}
int dfs(int u) {
    int s = 1;
    if (tree[u].left) s += dfs(tree[u].left);
    if (tree[u].right) s += dfs(tree[u].right);
    ans = ans * inv[s] % MOD;
    return s;
}
int build() {
    top = 0;
    for (int i = 1; i <= n; ++i)
        tree[i].left = tree[i].right = 0;
    for (int i = 1; i <= n; ++i) {
        int k = top;
        while (k && tree[stk[k - 1]] < tree[i]) --k;
        if (k) tree[stk[k - 1]].right = i;
        /*
        {
            tree[i].pre = stk[k - 1];
            tree[stk[k - 1]].right = i;
        }
        */
        if (k < top) tree[i].left = stk[k];
        /*
        {
            tree[stk[k]].pre = i;
            tree[i].left = stk[k];
        }
        */
        stk[k++] = i;
        top = k;
    }
    return stk[0];
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    init();
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &tree[i].value);
            tree[i].id = i;
        }
        int rt = build();
        ans = inv[2] * n % MOD;
        dfs(rt);
        printf("%lld\n", ans);
    }
    return 0;
}