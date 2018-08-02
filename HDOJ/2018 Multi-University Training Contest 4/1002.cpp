#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;
const int MAXT = 1e5 + 10;
const int MAXN = 1e5 + 10;
class Query {
public:
    int l, r, id;
}qst[MAXT];
int BLOCK;
LL tans, ans[MAXT], fac[MAXN], invfac[MAXN], inv2;
LL quickPow(LL base, LL r) {
    LL ret = 1;
    while (r) {
        if (r & 1) ret = (base * ret ) % MOD;
        base = (base * base) % MOD;
        r >>= 1;
    }
    return ret;
}
void init() {
    inv2 = quickPow(2, MOD - 2);
    fac[0] = invfac[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fac[i] = (fac[i - 1] * i) % MOD;
        invfac[i] = quickPow(fac[i], MOD - 2);
    }
}
bool cmp(const Query &a, const Query &b) {
    return a.l / BLOCK != b.l / BLOCK ? a.l / BLOCK < b.l / BLOCK : a.r < b.r;
}
LL getC(int n, int m) {
    if (m > n) return 0LL;
    return fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}
void addL(int l, int r) {
    tans = (tans + getC(r, l)) % MOD;
}
void addR(int l, int r) {
    tans = (2 * tans - getC(r, l) + MOD) % MOD;

}
void removeL(int l, int r) {
    tans = (tans - getC(r, l) + MOD) % MOD;
}
void removeR(int l, int r) {
    tans = ((tans + getC(r, l)) * inv2) % MOD;
}
int main() {
    // freopen("in.txt", "r", stdin);
    init();
    int T;
    scanf("%d", &T);
    BLOCK = sqrt(T);
    for (int i = 1; i <= T; ++i) {
        scanf("%d%d", &qst[i].r, &qst[i].l);
        qst[i].id = i;
    }
    sort(qst + 1, qst + T + 1, cmp);
    int L = qst[1].l;
    int R = L;
    tans = quickPow(2, L);
    for (int i = 1; i <= T; ++i) {
        while(L > qst[i].l)
            removeL(L--, R);
        while(L < qst[i].l)
            addL(++L, R);
        while(R > qst[i].r)
            removeR(L, --R);
        while(R < qst[i].r)
            addR(L, R++);
        ans[qst[i].id] = tans;
    }
    for (int i = 1; i <= T; ++i)
        printf("%lld\n", ans[i]);
    return 0;
}