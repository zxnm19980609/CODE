#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 100010;
class Node {
public:
    int a, b;
}monsters[MAXN];
int n, father[MAXN];
vector<int> edge[MAXN];
priority_queue<Node> pq;
void init() {
    for (int i = 1; i <= n; ++i)
        edge[i].clear();
}
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        init(n);
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &monsters[i].a, &monsters[i].b);
        for (int u, v, i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
    }
    return 0;
}