#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL n, m, a[105];
priority_queue<LL, vector<LL>, greater<LL>> pq;
int main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    LL mink = LLONG_MIN, maxk = LLONG_MIN;
    for (int i = 1; i <= n; ++i)
        maxk = max(maxk, a[i] + m);

    for (int i = 1; i <= n; ++i)
        pq.push(a[i]);
    while (m--) {
        LL t = pq.top();
        pq.pop();
        pq.push(t + 1);
    }
    while (!pq.empty()) {
        mink = max(mink, pq.top());
        pq.pop();
    }
    printf("%lld %lld\n", mink, maxk);
    return 0;
}