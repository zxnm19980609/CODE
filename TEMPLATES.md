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
```
