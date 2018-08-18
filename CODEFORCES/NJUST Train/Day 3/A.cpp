#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1000005;
int n, tmp[MAXN];
vector<int> v;
int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int x, i = 0; i < n; ++i) {
        cin >> x;
        tmp[x - 1] = i;
    }
    for (int x, i = 0; i < n; ++i) {
        cin >> x;
        v.push_back(tmp[x - 1]);
    }
    reverse(v.begin(), v.end());
    int len = 1;
    tmp[0] = v[0];
    for (int i = 1; i < n; ++i)
        if (v[i] > tmp[len - 1])
            tmp[len++] = v[i];
        else
            *lower_bound(tmp, tmp + len, v[i]) = v[i];
    cout << len << endl;
    return 0;
}