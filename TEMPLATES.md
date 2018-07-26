[TOC]

# 模板

## 排序

### 归并排序

```c++
/**
 * @brief 归并排序
 * @details 对 a[l...r] 进行排序，并求逆序对个数
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

