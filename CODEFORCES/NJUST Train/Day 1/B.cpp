#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string s, twoGram;
int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int n;
    cin >> n >> s;
    int mmax = -1;
    string ans;
    for (int i = 0; i < n - 1; ++i) {
        twoGram = s.substr(i, 2);
        int cnt = 0;
        for (int j = 0; j < n - 1; ++j)
            if (twoGram.compare(s.substr(j, 2)) == 0) ++cnt;
        if (cnt > mmax) {
            mmax = cnt;
            ans = twoGram;
        }
    }
    cout << ans << endl;
    return 0;
}