#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int phi[N + 5], prime[N + 5];
bool isprime[N + 5];
void init() {
    memset(isprime, 1, sizeof isprime);
    int cnt = 0;
    phi[1] = 1;
    for(int i = 2; i <= N; ++i) {
        if(isprime[i]) {
            prime[++cnt] = i;
            phi[i] = i - 1;
        }
        for(int j = 1; j <= cnt && prime[j] * i <= N; ++j){
            isprime[prime[j] * i] = false;
            if(i % prime[j] == 0) {
                phi[prime[j] * i] = prime[j] * phi[i];
                break;
            }
            else
                phi[prime[j] * i] = (prime[j] - 1) * phi[i];
        }
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    init();
    int ans = 0;
    for (int i = 1e3 + 1; i <= N; ++i)
        if (isprime[i]) ++ans;
    printf("%d\n", ans);
    return 0;
}