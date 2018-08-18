#include <cstdio>
#define lson p << 1
#define rson p << 1 | 1
using namespace std;
const char chr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
const int MAXN = 2e5 + 10;
class CNode {
public:
    int left, right, size, cnt[62];
} segtree[MAXN << 2];
int idx[129];
char ch;
inline void init() {
    int cnt = 0;
    for (int ch = 'a'; ch <= 'z'; ++ch) idx[ch] = cnt++;
    for (int ch = 'A'; ch <= 'Z'; ++ch) idx[ch] = cnt++;
    for (int ch = '0'; ch <= '9'; ++ch) idx[ch] = cnt++;
}
void build(int p, int l, int r) {
    segtree[p].left = l;
    segtree[p].right = r;
    if (l == r) {
        scanf(" %c ", &ch);
        segtree[p].cnt[idx[(int)ch]] = 1;
        segtree[p].size = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    for (int i = 0; i < 62; ++i) segtree[p].cnt[i] = segtree[lson].cnt[i] + segtree[rson].cnt[i];
    segtree[p].size = segtree[lson].size + segtree[rson].size;
}
int find(int p, int x) {
    if (segtree[p].left == segtree[p].right) return segtree[p].left;
    if (x <= segtree[lson].size)
        return find(lson, x);
    else
        return find(rson, x - segtree[lson].size);
}
void update(int p, int l, int r, int ch) {
    if (segtree[p].cnt[ch] == 0) return;
    if (segtree[p].left == segtree[p].right) {
        segtree[p].size = 0;
        segtree[p].cnt[ch] = 0;
        return;
    }
    int mid = (segtree[p].left + segtree[p].right) >> 1;
    if (r <= mid)
        update(lson, l, r, ch);
    else if (l > mid)
        update(rson, l, r, ch);
    else {
        update(lson, l, mid, ch);
        update(rson, mid + 1, r, ch);
    }
    segtree[p].cnt[ch] = segtree[lson].cnt[ch] + segtree[rson].cnt[ch];
    segtree[p].size = segtree[lson].size + segtree[rson].size;
}
void print(int p) {
    if (segtree[p].left == segtree[p].right) {
        for (int i = 0; i < 62; ++i)
            if (segtree[p].cnt[i]) {
                printf("%c", chr[i]);
                break;
            }
        return;
    }
    print(lson);
    print(rson);
}
int main() {
    // freopen("in.txt", "r", stdin);
    init();
    int n, m, l, r;
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    while (m--) {
        scanf(" %d %d %c ", &l, &r, &ch);
        l = find(1, l);
        r = find(1, r);
        update(1, l, r, idx[(int)ch]);
    }
    print(1);
    printf("\n");
    return 0;
}