#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int CHAR = 26;
const int MAXL = 1e5 + 5;
class SAMNode {
public:
    SAMNode *fa, *next[CHAR];
    int len;
    LL cnt;
    void clear() {
        fa = 0;
        memset(next, 0, sizeof next);
        cnt = 0;
    }
}pool[MAXL << 1];
SAMNode *root, *tail, *ed[MAXL], *toposam[MAXL << 1];
int a, b, ans, topocnt[MAXL];
char s[MAXL];
SAMNode* newNode(int len) {
    SAMNode *cur = tail++;
    cur->clear();
    cur->len = len;
    return cur;
}
void SAMInit() {
    tail = pool;
    root = newNode(0);
}
SAMNode* extend(SAMNode *last, int x) {
    SAMNode *p = last, *np = newNode(p->len + 1);
    while (p && !p->next[x]) {
        p->next[x] = np;
        p = p->fa;
    }
    if (!p)
        np->fa = root;
    else {
        SAMNode *q = p->next[x];
        if (q->len == p->len + 1)
            np->fa = q;
        else {
            SAMNode *nq = newNode(p->len + 1);
            memcpy(nq->next, q->next, sizeof(q->next));
            nq->fa = q->fa;
            q->fa = np->fa = nq;
            while (p && p->next[x] == q) {
                p->next[x] = nq;
                p = p->fa;
            }
        }
    }
    return np;
}
void dfs(SAMNode *now) {
    if (now->len >= a && now->len <= b)
        ans += now->cnt;
    for (int i = 0; i < 26; ++i)
        if (now->next[i])
            dfs(now->next[i]);
}
int main() {
    while (~scanf("%s%d%d", s + 1, &a, &b)) {
        SAMInit();
        memset(ed, 0, sizeof ed);
        ans = 0;
        ed[0] = root;
        for (int i = 1; s[i]; ++i) {
            ed[i] = extend(ed[i - 1], s[i] - 'A');
            ed[i]->cnt = 1;
        }
        memset(topocnt, 0, sizeof topocnt);
        int num = tail - pool;
        for (int i = 0; i < num; ++i)
            ++topocnt[pool[i].len];
        for (int i = 1; i <= n; ++i)
            topocnt[i] += topocnt[i - 1];
        for (int i = 0; i < num; ++i)
            toposam[--topocnt[pool[i].len]] = &pool[i];
        for (int i = num - 1; ~i; --i) {
            toposam[i]->cnt = 1;
            for (int j = 0; j < 26; ++j)
                if(p->next[i])
                    p->cnt += p->next[i]->cnt;
        }
        dfs(ed[0], 0);
        printf("%d\n", ans);
    }

    return 0;
}