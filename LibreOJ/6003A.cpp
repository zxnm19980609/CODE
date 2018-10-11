#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int n;
vector<int> a[MAXN];
bool check(int x) {
    int y = (int)(sqrt(x) + 0.5);
    if (y * y == x) return true;
    return false;
}
int main() {
    scanf("%d", &n);
    int num = 1;
    bool flag;
    do {
        flag = false;
        for (int i = 1; i <= n; ++i)
            if (a[i].empty() || check(num + *a[i].rbegin())) {
                flag = true;
                a[i].push_back(num++);
                break;
            }
    } while (flag);
    --num;
    printf("%d\n", num);
    for (int i = 1; i <= n; ++i) {
        bool flag = false;
        for (int x : a[i]) {
            if (flag)
                putchar(' ');
            else
                flag = true;
            printf("%d", x);
        }
        putchar('\n');
    }
    return 0;
}