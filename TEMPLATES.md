[TOC]

# 计算几何

## 凸包

```c++

```

# 数论

## 扩展欧几里得(EXGCD)

```c++
/**
 * @brief a * x + b * y = c 的最小正整数解
 *
 * @attention c % gcd(a, b) != 0 无解
 *            经过调整后得到的 x1 y1 为最小正整数解
 *            x = x1 +(or -) bg, y = y1 -(or +) ag 也是原方程的一组解
 */
LL exGcd_x, exGcd_y, exGcd_d;
void exGcd(LL a, LL b) {
    if (b == 0) {
        exGcd_x = 1;
        exGcd_y = 0;
        exGcd_d = a;
    }
    else {
        exGcd(b, a % b);
        LL tmp = exGcd_x;
        exGcd_x = exGcd_y;
        exGcd_y = tmp - a / b * exGcd_y;
    }
}
void solve(LL a, LL b, LL c) {
    LL gcd = __gcd(a, b);
    if (c % gcd) return;
    exGcd(a, b);
    LL x1, y1, ag, bg;
    ag = a / gcd;
    bg = b / gcd;
    x1 = (exGcd_x + bg) * (c / gcd);
    x1 = (x1 % bg + bg) % bg;
    y1 = (c - a * x1) / b;
}
```

## 概念 & 性质

1. **积性函数：** $$ \forall p > 0, q > 0, gcd(p, q) == 1 \quad f(p \cdot q ) = f(p) \cdot f(q) $$

2. **完全积性函数：** $$ \forall p > 0, q > 0, gcd(p, q) == 1 \quad f(p \cdot q ) = f(p) \cdot f(q) $$

3. **常见积性函数：**

   > $$ \varphi(n) $$－欧拉函数
   >
   > $$ \mu(n) $$－莫比乌斯函数
   >
   > $$ \lambda(n) $$－刘维尔函数
   >
   > $$ d(n) $$－n的正因子数目
   >
   > $$ \sigma(n) $$－n的所有正因子之和

4. **常见完全积性函数：**

   > $$ e(n) $$－元函数 $$ e(n) = \left[ n = 1\right] $$
   >
   > $$ I(n) $$－恒等函数 $$ I(n) = 1 $$
   >
   > $$ id(n) $$－单位函数 $$ id(n) = n $$

5. 积性函数 * 积性函数 = 积性函数

6. $$ a^n - 1 = (a - 1) * (a^{n - 1} + a^{n - 2} + \ldots + a^2 + a + 1 $$

7. $$ m \mid n \Rightarrow Fibonacci_m \mid Fibonacci_n $$

8. $$ gcd(Fibonacci_m, Fibonacci_n) = Fibonacci_{gcd(m, n)} $$

9. $$ gcd(2^m - 1, 2^n - 1) = 2^{gcd(m, n)} - 1 $$


## 快速幂

```c++
/**
 * @return a ^ b % MOD
 */
LL quickPow(LL a, LL b, LL MOD) {
    LL ret = 1LL;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
```

## 逆元

### 线性递推阶乘逆元

```c++
/**
 * @attention 适用于 MOD 较大的情况
 *            e.g. MOD == 1e9 + 7 || MOD == 998244353
 */
LL fac[N + 10], invfac[N + 10];
LL quickPow(LL a, LL b, LL MOD);
void init() {
    fac[0] = 1LL;
    for (int i = 1; i <= N; ++i) fac[i] = fac[i - 1] * i % MOD;
    invfac[N] = quickPow(fac[N], MOD - 2, MOD);
    for (int i = N - 1; ~i; --i)
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
}
```

## 组合数

### 杨辉三角

```c++
LL C[N + 10][N + 10];
void init(int n) {
    C[0][0] = 1;
    for(int i = 1; i < n; ++i) {
        C[i][0] = 1;
        for(int j = 1; j < i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        C[i][i] = 1;
    }
}
LL getC(int a, int b) {
    if(b > a) return 0;
    return C[a][b];
}
```

### $ \dbinom n r = \dfrac{n!}{r!(n-r)!} $

```c++
LL fac[N + 10];    // n!
LL invfac[N + 10]; // (n!) ^ (-1)
LL getC(LL a, LL b) {
    if (b > a) return 0;
    return fac[a] * invfac[b] % MOD * invfac[a - b] % MOD;
}
```

### Lucas定理

```c++
/**
 * @attention 适用于 a, b < 1e18, MOD < 1e5 的情况
 */
LL getC(int a, int b);
LL Lucas(LL a, LL b) {
    if(a < MOD && b < MOD) return getC(a, b);
    return getC(a % MOD, b % MOD) * Lucas(a / MOD, b / MOD);
}
```

## 欧拉定理

### 定理 & 性质

1. 若 $$ n, a $$ 为正整数，且 $ n, a $ 互质，则：

$$
a^{\varphi(n)} \equiv 1 \pmod n
$$

2. $$ \varphi(p^a) = (p - 1) * p^{a - 1} $$

### 线性筛 $ \varphi(n) $

```c++
/**
 * phi[p] = p - 1, p is prime.
 * phi[p * i] = p * phi[i], p is prime && p % i == 0.
 * phi[p * i] = (p - 1) * phi[i], p is prime && p % i != 0.
 */
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
```

## 莫比乌斯反演

### 定理 & 性质

1. **莫比乌斯反演定理：**

   > $$ F(n) $$ 和 $$ f(n) $$ 是定义在非负整数集合上的两个函数，并且满足条件： 
   > $$
   > F(n) = \sum \limits_{d \mid n} f(d)
   > $$
   > 那么存在一个结论：
   > $$
   > f(n) = \sum \limits_{d \mid n} \mu(d)F(\dfrac{n}{d})
   > $$
   >

   > 莫比乌斯反演有另外的一种形式，当 $$ F(n) $$ 和 $$ f(n) $$ 满足：
   > $$
   > F(n) = \sum \limits_{d \mid n} f(d)
   > $$
   > 可以推出：
   > $$
   > f(n) = \sum \limits_{n \mid d} \mu(\dfrac{d}{n})F(d)
   > $$
   >

2. $$ \sum \limits_{d \mid n} \mu(d) = \left[ n = 1 \right]$$

3. $$ \sum \limits_{d \mid n} \dfrac{\mu(d)}{d} = \dfrac{\varphi(n)}{n} $$ 

### 线性筛 $ \mu(d) $
```c++
int mu[N + 5], prime[N + 5];
bool isprime[N + 5];
void Mobius() {
    memset(isprime, 1, sizeof isprime);
    int cnt = 0;
    mu[1] = 1;
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= N; ++i) {
        if (isprime[i]) {
            prime[++cnt] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= cnt && prime[j] * i <= N; ++j) {
            isprime[prime[j] * i] = false;
            if (i % prime[j] == 0)
                break;
            else
                mu[prime[j] * i] = -mu[i];
        }
    }
}
```

### $ \lfloor \frac{n}{d} \rfloor $ 分块

```c++
int n, cnt, last;
for (int i = 1; i <= n; i = last + 1) {
    last = n / (n / i);
    cnt = last - i + 1;
}
```

## 矩阵快速幂

```c++
class Matrix {
public:
    int r, c;
    LL mat[MAX][MAX];
    Matrix() {
        r = c = 0;
        memset(mat, 0, sizeof mat);
    }
    Matrix(int n) : r(n), c(n) {
        memset(mat, 0, sizeof mat);
    }
    Matrix(int r, int c) : r(r), c(c) {
        memset(mat, 0, sizeof mat);
    }
    LL* operator[](int r) {
        return mat[r];
    }
    Matrix operator*(Matrix b) {
        Matrix ret(r, b.c);
        for (int i = 0; i < r; ++i)
            for (int k = 0; k < c; ++k)
            for (int j = 0; j < b.c; ++j)
                ret[i][j] = (ret[i][j] + mat[i][k] * b[k][j]) % MOD;
        return ret;
    }
};
Matrix fastPow(Matrix a, LL b) {
    Matrix ret(a.r, a.c);
    for (int i = 0; i < ret.r; ++i)
        ret[i][i] = 1;
    while (b) {
        if (b & 1) ret = ret * a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}
```

# 排序

## 归并排序

```c++
/**
 * @brief 归并排序
 *        对 a[l...r] 进行排序, 并求逆序对个数
 *
 * @param a 原数组
 * @param tmp 临时数组
 * @param cnt 逆序对个数
 */
void mergeSort(int a[], int tmp[], int l, int r, int &cnt) {
	if (l < r) {
		int m = (l + r) >> 1;
		mergeSort(a, tmp, l, m, cnt);
		mergeSort(a, tmp, m + 1, r, cnt);
        int i = l;
        int j = m + 1;
        int k = l;
        while (i <= m && j <= r) {
            if (a[i] > a[j]) {
                tmp[k++] = a[j++];
                cnt += m - i + 1;
            }
            else
                tmp[k++] = a[i++];
        }
        while (i <= m) tmp[k++] = a[i++];
        while (j <= r) tmp[k++] = a[j++];
        for (int fi = l; fi <= r; ++fi)
            a[fi] = tmp[fi];
	}
}
```

# 字符串

## 回文树

```c++
/**
  * 回文树 / 回文自动机
  *  pt[0] 连接了长度为偶数的回文子串
  *  pt[1] 连接了长度为奇数的回文子串
  */
namespace PalindromeTree {
    const int CHAR = 26;        // 字符集大小
    const int MAXL = 2000005;   // 字符串长度
    class PTNode {
    public:
        int cnt;        // 当前状态代表的回文子串的出现次数
        int len;        // 当前状态代表的回文子串的长度
        int fail;       // 失配后跳转到的不等于自身的最长后缀回文子串
        int right;      // 以当前状态代表的回文子串最后一个字符结尾的本质不同的回文子串的数量
        int next[CHAR]; // 当前状态代表的回文子串两侧添加字符 c 后得到的回文子串的状态
        void clear() {
            cnt = len = fail = right = 0;
            memset(next, 0, sizeof next);
        }
    }pt[MAXL];
    char str[MAXL];
    int num, suf;
    int newNode() {
        int cur = num++;
        pt[cur].clear();
        return cur;
    }
    void init() {
        num = 0;
        int p = newNode();
        pt[p].len = 0;
        p = pt[p].fail = newNode();
        pt[p].len = -1;
        pt[p].fail = p;
        suf = 0;
    }
    int getFail(int x, int l) {
        while (str[l - 1 - pt[x].len] != str[l])
            x = pt[x].fail;
        return x;
    }
    int extend(int x) {
        int c = str[x] - 'a';
        int p = getFail(suf, x);
        if (!pt[p].next[c]) {
            int q = newNode();
            pt[q].len = pt[p].len + 2;
            pt[q].fail = pt[getFail(pt[p].fail, x)].next[c];
            pt[q].right = pt[pt[q].fail].right + 1;
            pt[p].next[c] = q;
        }
        p = pt[p].next[c];
        ++pt[p].cnt;
        return suf = p;
    }
    void calc() {
        for (int i = num - 1; ~i; --i)
            pt[pt[i].fail].cnt += pt[i].cnt;
    }
    void build() {
        scanf("%s", str);
        for (int i = 0; str[i]; ++i)
            extend(i);
    }
}
```

## 后缀数组

```c++
/**
 * @attention 注意数组有效值的下标范围
 *            待排序数组长度为 n, 放在 0 到 n - 1 中, 在最后补 0 (小于字符集中的任何一个字符)
 *            e.g. n = 6, num[] = {1, 2, 3, 2, 3, 1, $} ($ 代表一个小于字符集中任意字符的字符)
 *            sa[]     1 到 n     为有效值
 *            rank[]   0 到 n - 1 为有效值
 *            height[] 2 到 n     为有效值
 */
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
     * @param m 字符集大小 (最大字符应小于 m)
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
}
```

## 后缀自动机

### e.g. `aabbabd`

> ![](D:\CODE\SAM.png)
>
> | 状态 | 子串                  | endpos          |
> | :--: | :-------------------- | --------------- |
> |  S   | 空串                  | {0,1,2,3,4,5,6} |
> |  1   | a                     | {1,2,5}         |
> |  2   | aa                    | {2}             |
> |  3   | aab                   | {3}             |
> |  4   | aabb,abb,bb           | {4}             |
> |  5   | b                     | {3,4,6}         |
> |  6   | aabba,abba,bba,ba     | {5}             |
> |  7   | aabbab,abbab,bbab,bab | {6}             |
> |  8   | ab                    | {3,6}           |

### 模板

```c++
/**
 * 后缀自动机
 *  sam[1] 表示初始状态 可认为是一个空串
 *  后缀自动机中的一个状态表示的是一系列结尾位置相同的字符串
 *  它们的结尾位置构成集合 endpos, 并且这些字符串的出现次数相同, 均为 cnt
 *  len 表示这些字符串的长度的最大值
 *  sam[p] 对应的 endpos 集合是 sam[p].fail 对应的 endpos 集合的子集
 */
namespace SAM {
    const int CHAR = 26;        // 字符集大小
    const int MAXL = 1e5 + 5;   // 字符串长度
    class SAMNode {
    public:
        int fail;       // 失配后跳转到不等于自身的最长后缀
        int len;        // 当前状态最长能接受的后缀长度
        int pos;        // 当前 endpos 集合中最小的数
                        // 即当前状态代表的后缀第一次出现时, 其结尾字符的位置
        LL cnt;         // 当前状态能接受的后缀的出现次数
        int next[CHAR]; // 当前状态代表的后缀后添加字符 c 后得到的后缀的状态
        void clear() {
            fail = len = pos = 0;
            memset(next, 0, sizeof next);
            cnt = 0;
        }
    }sam[MAXL << 1]; // 后缀自动机状态个数不超过 2 * MAXL 个
    int last, root, num, ed[MAXL];
    char s[MAXL];
    int newNode(int len, int pos) {
        int cur = ++num;
        sam[cur].clear();
        sam[cur].len = len;
        sam[cur].pos = pos;
        return cur;
    }
    void SAMInit() {
        num = 0;
        root = last = newNode(0, 0);
    }
    int extend(int last, int x) {
        int p = last, np = newNode(sam[p].len + 1, sam[p].len + 1);
        while (p && !sam[p].next[x]) {
            sam[p].next[x] = np;
            p = sam[p].fail;
        }
        if (!p)
            sam[np].fail = root;
        else {
            int q = sam[p].next[x];
            if (sam[q].len == sam[p].len + 1)
                sam[np].fail = q;
            else {
                int nq = newNode(sam[p].len + 1, sam[p].pos);
                memcpy(sam[nq].next, sam[q].next, sizeof sam[q].next);
                sam[nq].fail = sam[q].fail;
                sam[q].fail = sam[np].fail = nq;
                while (p && sam[p].next[x] == q) {
                    sam[p].next[x] = nq;
                    p = sam[p].fail;
                }
            }
        }
        sam[np].cnt = 1;
        return np;
    }
    void calc() {
        static int deg[MAXL << 1];
        memset(deg, 0, sizeof deg);
        static queue<int> que;
        while (!que.empty()) que.pop();
        for (int i = 1; i <= num; ++i)
            ++deg[sam[i].fail];
        for (int i = 1; i <= num; ++i)
            if (!deg[i]) que.push(i);
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            int fail = sam[now].fail;
            sam[fail].cnt += sam[now].cnt;
            if (--deg[fail] == 0) que.push(fail);
        }
    }
    void build() {
        SAMInit();
        scanf("%s", s + 1);
        memset(ed, 0, sizeof ed);
        ed[0] = root;
        for (int i = 1; s[i]; ++i)
            ed[i] = extend(ed[i - 1], s[i] - 'A');
    }
}
```

### 相关题目

1. **子串出现次数**

   > 在模式串T中查找子串P及其出现次数，建立T的后缀自动机，记录`cnt`表示当前状态的出现次数，如果当前结点新建得到，`cnt = 1`；如果当前结点拷贝得到，`cnt = 0`。
   >
   > 然后我们按照`fail`边的反向拓扑序，更新`cnt`变量，即：`sam[sam[p].fail].cnt += sam[p].cnt`。
   >
   > 然后对于子串，我们只需要在后缀自动机上跑出其对应状态结点p，然后查询`sam[p].cnt`即可。

2. 

# 图

## 拓扑排序

```c++
int n, indeg[MAXN];
vector<int> edge[MAXN];
queue<int> Q;
/**
 * @brief 有向图拓扑排序判环
 */
bool topoSort() {
    int cnt = 0;
    while (!Q.empty()) Q.pop();
    for (int i = 1; i <= n; ++i)
        if (indeg[i] == 0) {
            ++cnt;
            Q.push(i);
        }
    while (!Q.empty()) {
        int p = Q.front();
        Q.pop();
        for (int i = 0; i < (int)edge[p].size(); ++i)
            if (--indeg[edge[p][i]] == 0) {
                ++cnt;
                Q.push(edge[p][i]);
            }
    }
    if (cnt == n)
        return true;
    else
        return false;
}
```

## Tarjan - 强连通分量

```c++
class CEdge {
public:
    int x, next;
};
bool vis[MAXN];
int n, m, timestamp, color, cnt;
int h[MAXN], dfn[MAXN], low[MAXN], belong[MAXN];
CEdge edge[MAXM];
stack<int> s;
vector<int> G[MAXN];
void addEdge(int u,int v) {
    ++cnt;
    edge[cnt].x = v;
    edge[cnt].next = h[u];
    h[u] = cnt;
}
/**
 * @attention 注意多测时需要初始化的数组！
 */
void init() {
    while (!s.empty()) s.pop();
    cnt = 0;
    memset(h, 0, sizeof h);
    memset(vis, 0, sizeof vis);
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    timestamp = 0; color = 0;
    memset(belong, 0, sizeof belong);
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
}
void tarjan(int u) {
    int v;
    dfn[u] = low[u] = ++timestamp;
    s.push(u); vis[u] = true;
    for (int p = h[u]; p; p = edge[p].next) {
        v = edge[p].x;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++color;
        do {
            v = s.top();
            s.pop();
            vis[v] = false;
            belong[v] = color;
        } while (u != v);
    }
}
/**
 * @brief 强连通分量缩点
 *
 * @attention u, v 之间有边且 belong[u] != belong[v] 时,
 *            建一条 u -> v 的边
 */
void build() {
    for (int i = 1; i <= color; ++i) G[i].clear();
    for (int i = 1; i <= n; ++i)
        for (int p = h[i]; p; p = edge[p].next)
            if (belong[i] != belong[edge[p].x])
                G[belong[i]].push_back(belong[edge[p].x]);
}
int main() {
    init();
    for (int i = 1; i <= n; ++i)
        if (!dfn[i]) tarjan(i);
    build();
    return 0;
}
```

## 网络流

### 最大流

```c++
/**
 * @attention 有向图反向边初始流量为 0
 *            无向图反向边初始流量为 w
 */
class Edge {
public:
    int to, cap, next;
}edge[MAXM << 1];
int n, N, m, cnt, St, Ed, MEMORY_SIZE;
int h[MAXN], cur[MAXN], dis[MAXN];
int front, tail, que[MAXN];
void addEdge(int u, int v, int w, int rw = 0) {
    edge[cnt].to = v;
    edge[cnt].cap = w;
    edge[cnt].next = h[u];
    h[u] = cnt++;
    swap(u, v);
    edge[cnt].to = v;
    edge[cnt].cap = rw;
    edge[cnt].next = h[u];
    h[u] = cnt++;
}
bool bfs(int s, int t) {
    int u, v;
    memset(dis, -1, MEMORY_SIZE);
    front = tail = 0;
    que[tail++] = s;
    dis[s] = 0;
    while (front < tail) {
        u = que[front++];
        for (int p = h[u]; ~p; p = edge[p].next) {
            v = edge[p].to;
            if (dis[v] == -1 && edge[p].cap) {
                dis[v] = dis[u] + 1;
                if (v == t) return true;
                que[tail++] = v;
            }
        }
    }
    return false;
}
int dfs(int u, int t, int cap) {
    if (u == t || cap == 0) return cap;
    int res = 0, flow;
    for (int &p = cur[u]; ~p; p = edge[p].next) {
        int v = edge[p].to;
        if (dis[v] == dis[u] + 1 && (flow = dfs(v, t, min(cap - res, edge[p].cap) > 0))) {
            edge[p].cap -= flow;
            edge[p ^ 1].cap += flow;
            res += flow;
            if (res == cap) return cap;
        }
    }
    if (!res) dis[u] = -1;
    return res;
}
int dinic(int s, int t) {
    int ans = 0;
    while (bfs(s, t)) {
        memcpy(cur, h, MEMORY_SIZE);
        ans += dfs(s, t, INF);
    }
    return ans;
}
int main() {
    // freopen("in.txt", "r", stdin);
    int _;
    for (scanf("%d", &_); _; --_) {
        scanf("%d%d", &n, &m);
		scanf("%d%d", &St, &Ed);
        N = n;
        MEMORY_SIZE = (N + 1) * sizeof(int);
        cnt = 0;
        memset(h, -1, MEMORY_SIZE);
        for (int u, v, w, i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w, w);
        }
        printf("%d\n", dinic(St, Ed));
    }
    return 0;
}
```

### 最小费用最大流

```c++
class Edge {
public:
    int to, next, cap, flow, cost;
}edge[MAXE];
int h[MAXN], pre[MAXN], dis[MAXN];
int n, m, MEMORY_SIZE, St, Ed, cnt;
bool vis[MAXN];
void addEdge(int u, int v, int cap, int cost) {
    edge[cnt].to = v;
    edge[cnt].cap = cap;
    edge[cnt].cost = cost;
    edge[cnt].flow = 0;
    edge[cnt].next = h[u];
    h[u] = cnt++;
    edge[cnt].to = u;
    edge[cnt].cap = 0;
    edge[cnt].cost = -cost;
    edge[cnt].flow = 0;
    edge[cnt].next = h[v];
    h[v] = cnt++;
}
bool SPFA() {
    queue<int> Q;
    memset(dis, 0x3F, MEMORY_SIZE);
    memset(vis, 0, MEMORY_SIZE);
    memset(pre, -1, MEMORY_SIZE);
    dis[St] = 0;
    vis[St] = true;
    Q.push(St);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        vis[u] = false;
        for (int i = h[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            if (edge[i].cap > edge[i].flow && dis[v] > dis[u] + edge[i].cost) {
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i;
                if (!vis[v]) {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
    }
    return pre[Ed] != -1;
}
int MCMF(int &cost) {
    int flow = 0;
    cost = 0;
    while (SPFA()) {
        int Min = INF;
        for (int i = pre[Ed]; ~i; i = pre[edge[i ^ 1].to]) {
            if (Min > edge[i].cap - edge[i].flow)
                Min = edge[i].cap - edge[i].flow;
        }
        for (int i = pre[Ed]; ~i; i = pre[edge[i ^ 1].to]) {
            edge[i].flow += Min;
            edge[i ^ 1].flow -= Min;
            cost += edge[i].cost * Min;
        }
        flow += Min;
    }
    return flow;
}
int main() {
    scanf("%d%d", &n, &m);
    cnt = 0;
    MEMORY_SIZE = (n + 1) * sizeof(int);
    memset(h, -1, MEMORY_SIZE);
    for (int u, v, cap, cost, i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &u, &v, &cap, &cost);
        addEdge(u, v, cap, cost);
    }
    St = 1;
    Ed = n;
    int cost;
    int flow = MCMF(cost);
    printf("%d %d\n", flow, cost);
    return 0;
}
```

# 树

## LCA

```c++
int depth[MAXN], ancestor[MAXN][25];
vector<int> edge[MAXN];
void dfs(int u, int fa, int d) {
    depth[u] = d;
    ancestor[u][0] = fa;
    for (int i = 1; i < 25; ++i)
        ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
    for (auto &v : edge[u]) {
        if (v == fa) continue;
        dfs(v, u, d + 1);
    }
}
int LCA(int x, int y) {
    if (depth[x] < depth[y])
        swap(x, y);
    for (int i = 24; ~i; --i)
         if (depth[x] - (1 << i) >= depth[y])
            x = ancestor[x][i];
    if (x == y) return x;
    for (int i = 24; ~i; --i)
        if (ancestor[x][i] != ancestor[y][i]) {
            x = ancestor[x][i];
            y = ancestor[y][i];
        }
    return ancestor[x][0];
}
```

## 主席树

```c++
/**
 * 主席树: 可持久化线段树
 *        对于原序列 [1...n] 的每一个前缀 [1...i] 建立一棵线段树,
 *        第 i 棵线段树维护前缀 [1...i] 中属于 [L...R] 的数字的个数
 *
 * @brief 主席树解决静态区间第 K 小 ！！！
 *
 * @attention 注意数组大小, 20 - 50 倍 MAXN 即可
 *            对原序列进行离散化后再建树
 */
int n, q, m, cnt;
int a[MAXN], b[MAXN], root[MAXN * 20], lson[MAXN * 20], rson[MAXN * 20], sum[MAXN * 20];
void build(int& p, int l, int r) {
    p = ++cnt;
    sum[p] = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(lson[p], l, mid);
    build(rson[p], mid + 1, r);
}
void update(int& p, int l, int r, int last, int k) {
    p = ++cnt;
    lson[p] = lson[last];
    rson[p] = rson[last];
    sum[p] = sum[last] + 1;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (k <= mid)
        update(lson[p], l, mid, lson[last], k);
    else
        update(rson[p], mid + 1, r, rson[last], k);
}
int query(int ss, int tt,int l, int r, int k) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    int cnt = sum[lson[tt]] - sum[lson[ss]];
    if (k <= cnt)
        return query(lson[ss], lson[tt], l, mid, k);
    else
        return query(rson[ss], rson[tt], mid + 1, r, k - cnt);
}
inline void solve() {
    int ql, qr, x;
    scanf("%d%d%d", &ql, &qr, &x);
    int ans = query(root[ql - 1], root[qr], 1, m, x);
    printf("%d\n", b[ans]);
}
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), b[i] = a[i];
    sort(b + 1, b + n + 1);
    m = unique(b + 1, b + n + 1) - (b + 1);
    cnt = 0;
    build(root[0], 1, m);
    for (int i = 1; i <= n; ++i) a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
    for (int i = 1; i <= n; ++i) update(root[i], 1, m, root[i - 1], a[i]);
    while (q--) solve();
    return 0;
}
```

## 笛卡尔树

```c++
/**
 * 笛卡尔树满足如下两个性质
 *  1. 树中的元素满足二叉搜索树性质, 按照中序遍历得到的序列为原数组序列
 *  2. 树中节点满足堆性质, 节点的 value 大于其左右子节点的 value
 *
 * @brief 笛卡尔树节点
 *
 * @param left  左子节点
 * @param right 右子节点
 * @param pre   父节点
 * @param value
 *
 * @attention 重载小于号调整节点在树上的优先级
 */
class CartesianTree {
public:
    int left, right, pre, value;
    bool operator<(const CartesianTree &obj) const {
        return value < obj.value;
    }
}tree[MAXN];
int top, stk[MAXN];
/**
 * @brief 建树
 *
 * @return 树根节点编号
 */
int build(int n) {
    top = 0;
    for (int i = 1; i <= n; ++i)
        tree[i].left = tree[i].right = 0;
    for (int i = 1; i <= n; ++i) {
        int k = top;
        while (k && tree[stk[k - 1]] < tree[i]) --k;
        if (k) {
            tree[i].pre = stk[k - 1];
            tree[stk[k - 1]].right = i;
        }
        if (k < top) {
            tree[stk[k]].pre = i;
            tree[i].left = stk[k];
        }
        stk[k++] = i;
        top = k;
    }
    return stk[0];
}
```

# RMQ

## ST表

```c++
/**
 * @brief stMin[i][j] 表示 i 到 i + 2 ^ j - 1 这段区间的最小值
 *        stMin[i][0] = a[i]
 *
 * @attention 卡常数可以考虑预处理 2 ^ i 和 log()
 *            维护区间的范围: [1...n]
 */
int stMin[MAXN][31], stMax[MAXN][31];
void init(int n) {
    for(int j = 1; (1 << j) < n; ++j)
        for(int i = 1; i + (1 << j) - 1 <= n; ++i) {
            stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
            // stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
        }
}
int query(int l, int r) {
	int k = floor(log2(r - l + 1));
    return min(stMin[l][k], stMin[r - (1 << k) + 1][k]);
    // return max(stMax[l][k], stMax[r - (1 << k) + 1][k]);
}
```

# 杂项

## 快速读入

```c++
/**
 * @attention 只能用于读入整数
 *            不能和其他任何读入方法同时使用
 */
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
/**
 * @attention 可以和 scanf() 一起使用
 */
inline int read() {
    char ch = getchar();
    int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
```

## GCC 内建函数

```c++
/**
 * @brief GCC 内建函数, 高效位运算
 *        都是在二进制意义下
 *
 * @attention 这些函数的 unsigned long long 版本, 就是在
 *            函数名末尾加上 ll
 *            e.g. int __builtin_ctzll(unsigned long long n);
 */
int __builtin_popcount(unsigned int n); // 返回 '1' 的个数
int __builtin_parity(unsigned int n);   // 返回 '1' 的奇偶性
                                        // 1 表示奇数个 '1'
                                        // 0 表示偶数个 '1'
int __builtin_ffs(unsigned int n);      // 返回 n 末尾最后一个 '1' 的位置
int __builtin_ctz(unsigned int n);      // 返回 n 末尾 '0' 的个数
int __builtin_clz (unsigned int x);     // 返回前导 '0' 的个数
```

## 线性递推式

```c++
namespace linear_seq {
    const int N = 10010;
    LL res[N], base[N], _c[N], _md[N];
    vector<int> Md;
    void mul(LL *a, LL *b, int k) {
        for (int i = 0; i < k + k; ++i) _c[i] = 0;
        for (int i = 0; i < k; ++i)
            if (a[i]) {
                for (int j = 0; j < k ; ++j)
                    _c[i + j] = (_c[i + j] + a[i] * b[j]) % MOD;
            }
        for (int i = k + k - 1; i >= k; --i)
            if (_c[i]) {
                for (int j = 0; j < (int)Md.size(); ++j)
                    _c[i - k + Md[j]] = (_c[i - k + Md[j]] - _c[i] * _md[Md[j]]) % MOD;
            }
        for (int i = 0; i < k; ++i) a[i] = _c[i];
    }
    int solve(LL n, vector<int> a, vector<int> b) {
        LL ans = 0, pnt = 0;
        int k = (int)a.size();
        for (int i = 0; i < k; ++i)
            _md[k - 1 - i] = -a[i];
        _md[k] = 1;
        Md.clear();
        for (int i = 0; i < k; ++i)
            if (_md[i] != 0) Md.push_back(i);
        for (int i = 0; i < k; ++i)
            res[i] = base[i] = 0;
        res[0] = 1;
        while ((1ll << pnt) <= n) pnt++;
        for (int p = pnt; p >= 0; p--) {
            mul(res, res, k);
            if ((n >> p) & 1) {
                for (int i = k - 1; i >= 0; i--)
                    res[i + 1] = res[i];
                res[0] = 0;
                for (int j = 0; j < (int)Md.size(); ++j)
                    res[Md[j]] = (res[Md[j]] - res[k] * _md[Md[j]]) % MOD;
            }
        }
        for (int i = 0; i < k; ++i)
            ans = (ans + res[i] * b[i]) % MOD;
        if (ans < 0) ans += MOD;
        return ans;
    }
    vector<int> BM(vector<int> s) {
        vector<int> C(1, 1), B(1, 1);
        int L = 0, m = 1, b = 1;
        for (int n = 0; n < (int)s.size(); ++n) {
            LL d = 0;
            for (int i = 0; i <= L; ++i)
                d = (d + (LL)C[i] * s[n - i]) % MOD;
            if (d == 0) ++m;
            else if (2 * L <= n) {
                vector<int> T = C;
                LL c = MOD - d * quickPow(b, MOD - 2, MOD) % MOD;
                while ((int)C.size() < (int)B.size() + m) C.push_back(0);
                for (int i = 0; i < (int)B.size(); ++i)
                    C[i + m] = (C[i + m] + c * B[i]) % MOD;
                L = n + 1 - L; m = 1;
                B = T; b = d;
            }
            else {
                LL c = MOD - d * quickPow(b, MOD - 2, MOD) % MOD;
                while ((int)C.size() < (int)B.size() + m) C.push_back(0);
                for (int i = 0; i < (int)B.size(); ++i)
                    C[i + m] = (C[i + m] + c * B[i]) % MOD;
                ++m;
            }
        }
        return C;
    }
    int gao(vector<int> a, LL n) {
        vector<int> c = BM(a);
        c.erase(c.begin());
        for (int i = 0; i < (int)c.size(); ++i)
            c[i] = (MOD - c[i]) % MOD;
        return solve(n, c, vector<int>(a.begin(), a.begin() + (int)c.size()));
    }
}
```
