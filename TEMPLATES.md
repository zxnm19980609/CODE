[TOC]

# 模板

## 计算几何

### 凸包

```c++

```

## 数论

### 概念 & 性质

1. **积性函数：**$$ \forall p > 0, q > 0, gcd(p, q) == 1 \quad f(p \cdot q ) = f(p) \cdot f(q) $$

2. **完全积性函数：**$$ \forall p > 0, q > 0, gcd(p, q) == 1 \quad f(p \cdot q ) = f(p) \cdot f(q) $$

3. **常见积性函数：**

   > $$ \varphi(n) $$－欧拉函数
   >
   > $$\mu(n)$$－莫比乌斯函数
   >
   > $$\lambda(n)$$－刘维尔函数
   >
   > $$d(n)$$－n的正因子数目
   >
   > $$\sigma(n)$$－n的所有正因子之和

4. **常见完全积性函数：**

   > $$ e(n) $$－元函数 $$ e(n) = \left[ n = 1\right] $$
   >
   > $$I(n)$$－恒等函数 $$ I(n) = 1 $$
   >
   > $$id(n)$$－单位函数 $$ id(n) = n $$

5. 积性函数 * 积性函数 = 积性函数

6. $$ a^n - 1 = (a - 1) * (a^{n - 1} + a^{n - 2} + \ldots + a^2 + a + 1$$

7. $$ m \mid n \Rightarrow Fibonacci_m \mid Fibonacci_n $$

8. $$ gcd(Fibonacci_m, Fibonacci_n) = Fibonacci_{gcd(m, n)} $$

9. $$ gcd(2^m - 1, 2^n - 1) = 2^{gcd(m, n)} - 1 $$

10. 

### 快速幂

```c++
typedef long long LL;
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

### 逆元

#### 线性递推阶乘逆元

```c++
/**
 * @attention 适用于 MOD 较大的情况
 *            e.g. MOD == 1e9 + 7 || MOD == 998244353
 */
#include <cmath>
typedef long long LL;
const int MOD = 998244353;
const int N = 3e5 + 5;
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

### 组合数

#### 杨辉三角

```c++
typedef long long LL;
const int MOD = 1e9 + 7;
const int N = 1005;
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

#### $ \dbinom n r = \dfrac{n!}{r!(n-r)!} $ 

```c++
typedef long long LL;
const int MOD = 998244353;
const int N = 3e5 + 5;
LL fac[N + 10];    // n!
LL invfac[N + 10]; // (n!) ^ (-1)
LL getC(LL a, LL b) {
    if (b > a) return 0;
    return fac[a] * invfac[b] % MOD * invfac[a - b] % MOD;
}
```

#### Lucas定理

```c++
/**
 * @attention 适用于 a, b < 1e18, MOD < 1e5 的情况
 */
typedef long long LL;
const int MOD = 1e5 + 7;
LL getC(int a, int b);
LL Lucas(LL a, LL b) {
    if(a < MOD && b < MOD) return getC(a, b);
    return getC(a % MOD, b % MOD) * Lucas(a / MOD, b / MOD);
}
```

### 欧拉定理

#### 定理 & 性质

若 $$ n, a $$ 为正整数，且 $$ n, a $$ 互质，则：
$$
a^{\varphi(n)} \equiv 1 \pmod p
$$


## 莫比乌斯反演

#### 定理 & 性质

1. 

2. **莫比乌斯反演定理：**

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

3. fff

4. $$ \sum \limits_{d \mid n} \mu(d) = \left[ n = 1 \right]$$

5. $$ \sum \limits_{d \mid n} \dfrac{\mu(d)}{d} = \dfrac{\varphi(n)}{n} $$ 

### $ \lfloor \frac{n}{d} \rfloor $ 分块

```c++
int n, cnt, last;
for (int i = 1; i <= n; i = last + 1) {
    last = n / (n / i);
    cnt = last - i + 1;
}
```

#### 线性筛 $ \mu(d) $

```c++

```

## 排序

### 归并排序

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

## 矩阵快速幂

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX = 150;
LL MOD;
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

## 图

### 网络流

1. 

### 最大流

```c++
/**
 * @attention 有向图反向边初始流量为 0
 *            无向图反向边初始流量为 w
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 100010;
const int MAXM = 100010;
const int INF = 0x3F3F3F3F;
class Edge {
public:
    int x, w, next;
}edge[MAXM << 1];
int n, m, cnt, S, T, MEMORY_SIZE;
int h[MAXN], cur[MAXN], dis[MAXN];
queue<int> Q;
void addEdge(int u, int v, int w) {
    edge[cnt].x = v;
    edge[cnt].w = w;
    edge[cnt].next = h[u];
    h[u] = cnt++;
}
bool bfs(int s, int t) {
    int u, v;
    memset(dis + 1, -1, MEMORY_SIZE);
    Q.push(s);
    dis[s] = 0;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (int p = h[u]; ~p; p = edge[p].next) {
            v = edge[p].x;
            if (dis[v] == -1 && edge[p].w) {
                dis[v] = dis[u] + 1;
                Q.push(v);
                if (v == t) break;
            }
        }
    }
    return dis[t] != -1;
}
int dfs(int u, int t, int cap) {
    if (u == t || cap == 0) return cap;
    int res = 0, flow;
    for (int &p = cur[u]; ~p; p = edge[p].next) {
        int v = edge[p].x;
        if (dis[v] == dis[u] + 1 && (flow = dfs(v, t, min(cap - res, edge[p].w))) > 0) {
            edge[p].w -= flow;
            edge[p ^ 1].w += flow;
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
        memcpy(cur + 1, h + 1, MEMORY_SIZE);
        ans += dfs(s, t, INF);
    }
    return ans;
}
int main() {
    // freopen("in.txt", "r", stdin);
    int _;
    for (scanf("%d", &_); _; --_) {
        scanf("%d%d", &n, &m);
		scanf("%d%d", &S, &T);
        MEMORY_SIZE = n * sizeof(int);
        cnt = 0;
        memset(h + 1, -1, MEMORY_SIZE);
        for (int u, v, w, i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        printf("%d\n", dinic(S, T));
    }
    return 0;
}
```



## 树

### 笛卡尔树

```c++
const int MAXN = 1e6 + 10;
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

## RMQ

### ST表

```c++
/**
 * @brief stMin[i][j] 表示 i 到 i + 2 ^ j - 1 这段区间的最小值
 *        stMin[i][0] = a[i]
 *
 * @attention 卡常数可以考虑预处理 2 ^ i 和 log()
 */
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int stMin[MAXN][31], stMax[MAXN][31];
void init(int n) {
    for(int j = 1; (1 << j) < n; ++j)
        for(int i = 0; i + (1 << j) - 1 < n; ++i) {
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



## 杂项

### 快速读入

```c++
#include <cstdio>
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

### GCC 内建函数

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

