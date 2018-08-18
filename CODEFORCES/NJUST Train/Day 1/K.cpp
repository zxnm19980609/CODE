#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
int n;
LL w, a;
int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> w;
    LL l = 0, r = w;
    for (int t, i = 1; i <= n; ++i) {
        cin >> t;
        a += t;
        if (a < 0LL)
            l = max(l, -a);
        else
            r = min(r, w - a);
    }
    cout << max(0LL, r - l + 1) << endl;
    return 0;
}