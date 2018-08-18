#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
vector<LL> a;
int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    for (int i = 0; i < 14; ++i) {
        LL t;
        cin >> t;
        a.push_back(t);
    }
    LL ans = 0;
    for (int i = 0; i < 14; ++i) {
        vector<LL> tmp(a);
        LL t = tmp[i];
        tmp[i] = 0LL;
        int j;
        for (j = 0; j < 14; ++j)
            tmp[j] += t / 14;
        j = (i + 1) % 14;
        for (int k = 0; k < t % 14; ++k) {
            ++tmp[j];
            j = (j + 1) % 14;
        }
        LL tans = 0;
        for (j = 0; j < 14; ++j)
            if (!(tmp[j] & 1)) tans += tmp[j];
        ans = max(ans, tans);
    }
    cout << ans << endl;
    return 0;
}