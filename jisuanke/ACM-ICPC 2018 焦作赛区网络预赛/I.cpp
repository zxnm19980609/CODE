#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c;
    while (~scanf("%d%d%d", &a, &b, &c)) {
        if ((a * b * c) & 1)
            puts("No");
        else
            puts("Yes");
    }
    return 0;
}