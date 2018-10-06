#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 5;
string message[MAX];
bool rep[MAX];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(rep, 1, sizeof rep);
    for (int t, i = 1; i <= m; ++i) {
        cin >> t >> message[i];
        if (i == 1 || message[i].compare(message[i - 1]))
            rep[t] = false;
    }
    bool flag = false;
    for (int i = 1; i <= n; ++i)
        if (rep[i]) {
            if (flag)
                putchar(' ');
            else
                flag = true;
            printf("%d", i);
        }
    putchar('\n');
    return 0;
}