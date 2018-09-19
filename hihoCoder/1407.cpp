#include <bits/stdc++.h>
using namespace std;
namespace SuffixArray {
    const int MAXL = 1e5 + 5;
    int sa[MAXL];       // 排名为 i 的后缀的开始位置
    int rank[MAXL];     // suffix(i) 的排名
    int height[MAXL];   // LCP(suffix(sa[i]), suffix(sa[i - 1]))
    int stMin[MAXL][31];
    int t1[MAXL], t2[MAXL], c[MAXL];
    int n, num[MAXL];
    bool cmp(int r[], int a, int b, int l) {
        return r[a] == r[b] && r[a + l] == r[b + l];
    }
    /**
     * @param s 字符串
     * @param n 字符串长度
     * @param m 字符集大小
     */
    void da(int s[], int n, int m) {
        s[n] = 0;
        ++n;
        int p, *x = t1, *y = t2;
        for (int i = 0; i < m; ++i) c[i] = 0;
        for (int i = 0; i < n; ++i) ++c[x[i] = s[i]];
        for (int i = 1; i < m; ++i) c[i] += c[i - 1];
        for (int i = n - 1; ~i; --i) sa[--c[x[i]]] = i;
        for (int j = 1; j <= n; j <<= 1) {
            p = 0;
            for (int i = n - j; i < n; ++i) y[p++] = i;
            for (int i = 0; i < n; ++i)
                if (sa[i] >= j) y[p++] = sa[i] - j;
            for (int i = 0; i < m; ++i) c[i] = 0;
            for (int i = 0; i < n; ++i) ++c[x[y[i]]];
            for (int i = 1; i < m; ++i) c[i] += c[i - 1];
            for (int i = n - 1; ~i; --i) sa[--c[x[y[i]]]] = y[i];
            swap(x, y);
            p = 1;
            x[sa[0]] = 0;
            for (int i = 1; i < n; ++i)
                x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
            if (p >= n) break;
            m = p;
        }
        int k = 0;
        --n;
        for (int i = 0; i <= n; ++i) rank[sa[i]] = i;
        for (int i = 0; i < n; ++i) {
            if (k) --k;
            int j = sa[rank[i] - 1];
            while (s[i + k] == s[j + k]) ++k;
            height[rank[i]] = k;
        }
    }
    void initRMQ(int n) {
        for (int i = 0; i < n; ++i)
            stMin[i][0] = height[i];
        for (int j = 1; (1 << j) < n; ++j)
            for (int i = 0; i + (1 << j) - 1 < n; ++i)
                stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
    }
    int query(int l, int r) {
        int k = floor(log2(r - l + 1));
        return min(stMin[l][k], stMin[r - (1 << k) + 1][k]);
    }
    /**
     * @return LCP(suffix(a), suffix(b))
     */
    int LCP(int a, int b) {
        a = rank[a];
        b = rank[b];
        if (a > b) swap(a, b);
        return height[query(a + 1, b)];
    }
    bool check(int k) {
        int minp = INT_MAX, maxp = INT_MIN;
        for (int i = 2; i <= n; ++i)
            if (height[i] < k) {
                minp = sa[i];
                maxp = sa[i];
            }
            else {
                minp = min(minp, sa[i]);
                maxp = max(maxp, sa[i]);
                if (maxp - minp >= k)
                    return true;
            }
        return false;
    }
    void solve() {
        scanf("%d", &n);
        int m =  0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &num[i]);
            m = max(m, num[i]);
        }
        da(num, n, m + 1);
        int l = 1, r = n, ans = 0;
        while (l <= r) {
            m = (l + r) >> 1;
            if (check(m)) {
                ans = max(ans, m);
                l = m + 1;
            }
            else
                r = m - 1;
        }
        printf("%d\n", ans);
    }
}
int main() {
    SuffixArray::solve();
    return 0;
}