#include <cstdio>
#include <iostream>
using namespace std;
typedef unsigned long long ULL;
ULL n, m, x;
int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> x;
        if (m >= n / 2)
            cout << n / 2 << ' ' << n / 2 * (n - n / 2) * x << endl;
        else
            cout << m << ' ' << m * (n - m) * x << endl;
    }
    return 0;
}