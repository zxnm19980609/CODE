#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0, p = 1;
    while (n) {
        if (n >= p)
            n -= p;
        else
            n = 0;
        p <<= 1;
        ++cnt;
    }
    printf("%d\n", cnt);
    return 0;
}