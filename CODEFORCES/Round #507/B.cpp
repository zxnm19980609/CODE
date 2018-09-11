#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> ans;
    while (n) {
        int m = min(n, 2 * k + 1);
        ans.push_back(m);
        n -= m;
    }
    if ((int)ans.size() == 1) {
        printf("1\n%d\n", (n + 1) / 2);
        return 0;
    }
    if (*ans.rbegin() < k + 1) {
        int delta = k + 1 - *ans.rbegin();
        *ans.rbegin() += delta;
        *ans.begin() -= delta;
    }
    printf("%d\n", (int)ans.size());
    int last = 0;
    for (auto& len : ans) {
        printf("%d ", last + len - k);
        last += len;
    }
    return 0;
}