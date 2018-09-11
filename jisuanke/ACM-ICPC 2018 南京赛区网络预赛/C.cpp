#include <bits/stdc++.h>
using namespace std;
const int MAXM = 2e4 + 5;
const int MAXN = 205;
multiset<int> p[MAXN];
int n, m, ct, c[MAXM];
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int tcas = 1; tcas <= T; ++tcas) {
        printf("Case #%d:\n", tcas);
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            p[i].clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d", &c[i]);
            if (c[i] < 3) c[i] += 13;
        }
        ct = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 5 && ct < m; ++j)
                p[i].insert(c[ct++]);

        int start = 0, card, play;
        bool deal = false;
        bool first = true;
        while (true) {
            if (deal) {
                for (int i = 0; i < n && ct < m; ++i)
                    p[(start + i) % n].insert(c[ct++]);
                deal = false;
            }

            if (first) {
                auto it = p[start].begin();
                card = *it;
                p[start].erase(it);
                if (p[start].empty())
                    goto END;
                first = false;
            }

            bool flag = false;
            for (int i = (start + 1) % n; i != start; i = (i + 1) % n) {
                if (card == 15) break;
                auto it = p[i].find(card + 1);
                if (it != p[i].end()) {
                    p[i].erase(it);
                    card = card + 1;
                    play = i;
                    flag = true;
                    if (p[i].empty())
                        goto END;
                    break;
                }
                it = p[i].find(15);
                if (it != p[i].end()) {
                    p[i].erase(it);
                    card = 15;
                    play = i;
                    flag = true;
                    if (p[i].empty())
                        goto END;
                    break;
                }
            }
            if (flag) {
                deal = first = false;
                start = play;
            }
            else
                deal = first = true;
        }

END:
        for (int i = 0; i < n; ++i)
            if (p[i].empty())
                puts("Winner");
            else {
                int sum = 0;
                for (auto & x : p[i])
                    sum += (x > 13 ? x - 13 : x);
                printf("%d\n", sum);
            }
    }
    return 0;
}