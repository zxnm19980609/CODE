#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 2e5 + 10;
class Query {
public:
    int l, r, blockNo, id;
}qst[MAX];
int n, m, q, BLOCK, ans[MAX], ansK, ansKP1;
int faKP1[MAX], faK[MAX];
pair<int, int> edge[MAX];
void initFather(int father[]) {
    for (int i = 1; i <= n; ++i)
        father[i] = i;
}
int unionFind(int father[], int x) {
    if (father[x] == x) return x;
    return father[x] = unionFind(father, father[x]);
}
void unionMerge(int father[], int x, int y) {
    int fx = unionFind(father, x);
    int fy = unionFind(father, y);
    if (fx != fy) {
        if (father == faKP1)
            --ansKP1;
        else
            --ansK;
        father[fx] = fy;
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &q);
        BLOCK = sqrt(m);
        for (int i = 1; i <= m; ++i)
            scanf("%d%d", &edge[i].first, &edge[i].second);
        for (int i = 1; i <= q; ++i) {
            scanf("%d%d", &qst[i].l, &qst[i].r);
            qst[i].blockNo = qst[i].l / BLOCK + 1;
            qst[i].id = i;
        }
        sort(qst + 1, qst + q + 1, [](const Query &a, const Query &b) {
            return a.blockNo != b.blockNo ? a.blockNo < b.blockNo : a.r < b.r;
        });
        initFather(faK);
        for (int i = 1; i <= q; ++i) {
            if (qst[i].blockNo > qst[i - 1].blockNo) {
                ansKP1 = n;
                initFather(faKP1);
                for (int j = qst[i].blockNo * BLOCK; j <= qst[i].r; ++j)
                    unionMerge(faKP1, edge[j].first, edge[j].second);
            }
            else {
                for (int j = max(qst[i - 1].r + 1, qst[i].blockNo * BLOCK); j <= qst[i].r; ++j)
                    unionMerge(faKP1, edge[j].first, edge[j].second);
            }
            ansK = ansKP1;
            int lim = min(qst[i].r, qst[i].blockNo * BLOCK - 1);
            for (int j = qst[i].l; j <= lim; ++j)
                unionMerge(faK, unionFind(faKP1, edge[j].first), unionFind(faKP1, edge[j].second));
            ans[qst[i].id] = ansK;
            for (int j = qst[i].l; j <= lim; ++j) {
                faK[faKP1[edge[j].first]] = faKP1[edge[j].first];
                faK[faKP1[edge[j].second]] = faKP1[edge[j].second];
            }
        }
        for (int i = 1; i <= q; ++i)
            printf("%d\n", ans[i]);
    }
    return 0;
}