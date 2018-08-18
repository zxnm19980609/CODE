#include <cstdio>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
const int MAX = 2e5 + 5;
int n, m, t, last[MAX];
queue<int> qlt[MAX];
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        int pos = upper_bound(last, last + m, t, greater<int>()) - last;
        if (pos == m) ++m;
        qlt[pos].push(t);
        last[pos] = t;
    }
    for (int i = 0; i < m; ++i) {
        while (!qlt[i].empty()) {
            printf("%d ", qlt[i].front());
            qlt[i].pop();
        }
        putchar('\n');
    }
    return 0;
}
