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

