#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int MAXP = 65;
int n, p, m, A[MAXN][MAXP], B[MAXP][MAXN];
char s[MAXP];
int main() {
    scanf("%d%d%d", &n, &p, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < p; ++j)
            scanf("%x", &A[i][j]);
    for (int j = 0; j < m; ++j) {
        scanf(" %s ", s);
        for (int i = 0; s[i]; ++i)
            B[i][j] = s[i] == '0' ? 0 : 1;
    }
    return 0;
}