[TOC]

# 模板

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

## 计算几何

### 凸包

```c++

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



## 杂项

### 快速读入

```c++
#include <cstdio>
/**
 * @brief 快速读入
 *
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

