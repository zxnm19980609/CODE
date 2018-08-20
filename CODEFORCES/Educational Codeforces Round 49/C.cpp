#include <bits/stdc++.h>
using namespace std;
const int MAXA = 1e4 + 5;
int n, cnt[MAXA];
vector<int> v;
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        v.clear();
        memset(cnt, 0, sizeof cnt);
        scanf("%d", &n);
        for (int t, i = 1; i <= n; ++i) {
            scanf("%d", &t);
            ++cnt[t];
            if (cnt[t] == 2 || cnt[t] == 4) v.push_back(t);
        }
        sort(v.begin(), v.end());
        double mmin = -1.0;
        int ansa, ansb;
        for (int i = 1; i < (int)v.size(); ++i) {
            int a = v[i - 1];
            int b = v[i];
            double P = 2 * (a + b);
            double S = a * b;
            double f = P * P / S;
            if (mmin < 0 || mmin > f) {
                mmin = f;
                ansa = a;
                ansb = b;
            }
        }
        printf("%d %d %d %d\n", ansa, ansa, ansb, ansb);
    }
    return 0;
}