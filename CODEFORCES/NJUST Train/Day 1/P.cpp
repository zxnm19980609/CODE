#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 200005;
int n, q;
long long arrows, k, a[MAX];
int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    while (q--) {
        cin >> k;
        arrows += k;
        if (arrows >= a[n]) {
            arrows = 0LL;
            cout << n << endl;
        }
        else
            cout << n - int(upper_bound(a + 1, a + n + 1, arrows) - a - 1) << endl;
    }
    return 0;
}