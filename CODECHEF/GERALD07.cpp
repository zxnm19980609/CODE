#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXQ = 2e5 + 10;
const int MAXM = 2e5 + 10;
class Query {
public:
    int l, r, blockNo, id;
}qst[MAXQ];
int n, m, q, BLOCK, ans[MAXQ];
int faKP1[MAXM], faK[MAXM];
pair<int, int> edge[MAXM];
void initFather(int father[]) {
    for (int i = 1; i <= m; ++i)
        father[i] = i;
}
int unionFind(int father[], int x) {
    if (father[x] == x) return x;
    return father[x] = unionFind(father, father[x]);
}
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &q);
    BLOCK = sqrt(m);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &edge[i].first, &edge[i].second);
    for (int i = 1; i <= q; ++i) {
        scanf("%d%d", &qst[i].l, &qst[i].r);
        qst[i].blockNo = qst[i].l / BLOCK + 1;
        qst[i].id = i;
    }
    sort(qst + 1, qst + n + 1, [](const Query &a, const Query &b) {
        return a.blockNo != b.blockNo ? a.blockNo < b.blockNo : a.r < b.r;
    });
    initFather(faK);
    for (int i = 1; i <= q; ++i) {
        if (qst[i].blockNo > qst[i - 1].blockNo) {
            ans[0] = n;
            for (int j = 1; j <= n; ++j)
                faKP1[j] = j;
            for (int j = qst[i].blockNo * BLOCK; j <= qst[i].r; ++j)
                unionFind()
        }
    }
    return 0;
}