#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    long long n, k;
    cin >> n >> k;
    cout << max(0LL, min(n, k - 1) - (k / 2 + 1) + 1);
    return 0;
}