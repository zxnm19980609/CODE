#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
LL a[110], ans[110];
set<LL> vis;
int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        vis.clear();
        for (int j = 0; j < n; ++j) vis.insert(a[j]);
        ans[0] = a[i];
        vis.erase(ans[0]);
        bool flag = true;
        for (int j = 1; j < n; ++j) {
            LL x = ans[j - 1] * 2LL;
            LL y = (ans[j - 1] % 3LL == 0) ? ans[j - 1] / 3LL : -1;
            if (vis.find(x) != vis.end()) {
                ans[j] = x;
                vis.erase(x);
            }
            else if (vis.find(y) != vis.end()) {
                ans[j] = y;
                vis.erase(y);
            }
            else {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << ans[0];
            for (int j = 1; j < n; ++j)
                cout << ' ' << ans[j];
            cout << endl;
            break;
        }
    }
    return 0;
}