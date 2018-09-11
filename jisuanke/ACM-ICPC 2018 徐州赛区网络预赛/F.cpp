#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> *pre, *now;
map<pair<int, int>, int>::iterator mit;
int main() {
    pre = new map<pair<int, int>, int>;
    now = new map<pair<int, int>, int>;
    pair<int, int> f;
    int T, n, cnt, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        pre->clear();
        now->clear();
        ans = 0;
        for (int k, i = 0; i < n; ++i) {
            scanf("%d", &k);
            now->clear();
            for (int j = 0; j < k; ++j) {
                scanf("%d%d", &f.first, &f.second);
                mit = pre->find(f);
                cnt = mit == pre->end() ? 1 : mit->second + 1;
                ans = max(ans, cnt);
                now->insert(make_pair(f, cnt));
            }
            swap(pre, now);
        }
        printf("%d\n", ans);
    }
    return 0;
}