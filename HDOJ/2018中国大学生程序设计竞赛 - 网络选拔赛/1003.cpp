#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("in.txt", "r", stdin);
    int T, p;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &p);
        for (int i = 0; i < p; ++i)
            for (int j = 0; j < p; ++j)
                printf(j == p - 1 ? "%d\n" : "%d ", (i + j) % p);
        for (int i = 0; i < p; ++i)
            for (int j = 0; j < p; ++j)
                printf(j == p - 1 ? "%d\n" : "%d ", (i * j) % p);
    }
    return 0;
}