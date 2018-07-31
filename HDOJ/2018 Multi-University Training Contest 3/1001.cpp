#include <cstdio>
#include <deque>
using namespace std;
namespace FastIO {
    inline char nc() {
        static char buf[100000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? '@' : *p1++;
    }
    int over;
    inline int nextInt() {
        char ch = nc();
        int s = 0;
        while(!(ch >= '0' && ch <= '9')) {
            ch = nc();
            if(ch == '@') { over = 1; break; }
        }
        while(ch >= '0' && ch <= '9') {
            s = s * 10 + ch - 48, ch = nc();
            if(ch == '@') { over = 1; break; }
        }
        return s;
    }
}
const int MAXN = 1e7 + 10;
int n, m, k;
long long p, q, r, mod;
int a[MAXN], mx[MAXN], cnt[MAXN];
deque<pair<int, int> > dq;
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    T = FastIO::nextInt();
    while (T--) {
        n = FastIO::nextInt();
        m = FastIO::nextInt();
        k = FastIO::nextInt();
        p = FastIO::nextInt();
        q = FastIO::nextInt();
        r = FastIO::nextInt();
        mod = FastIO::nextInt();
        for (int i = 1; i <= k; ++i)
            a[i] = FastIO::nextInt();
        for (int i = k + 1; i <= n; ++i)
            a[i] = (p * a[i - 1] + q * i + r) % mod;
        dq.clear();
        for (int i = n; i; --i) {
            if (!dq.empty() && (*dq.rbegin()).second - i >= m) dq.pop_back();
            while (!dq.empty() && (*dq.begin()).first <= a[i]) dq.pop_front();
            dq.push_front(make_pair(a[i], i));
            mx[i] = (*dq.rbegin()).first;
            cnt[i] = (int)dq.size();
        }
        long long ansmx = 0, anscnt = 0;
        for (int i = 1; i <= n - m + 1; ++i) {
            ansmx += mx[i] ^ i;
            anscnt += cnt[i] ^ i;
        }
        printf("%lld %lld\n", ansmx, anscnt);
    }
    return 0;
}