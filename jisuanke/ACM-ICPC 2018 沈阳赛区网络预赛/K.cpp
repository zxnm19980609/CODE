#include <bits/stdc++.h>
using namespace std;
const int ans[] = {1, 2, 3, 5, 7, 11, 13, 17, 23, 31,
                   37, 53, 71, 73, 113, 131, 137, 173,
                   311, 317, 0};
int main() {
    int T, n;
    char s[110];
    scanf("%d", &T);
    for (int tcas = 1; tcas <= T; ++tcas) {
        printf("Case #%d: ", tcas);
        scanf("%s", s);
        if (strlen(s) >= 4)
            puts("317");
        else {
            sscanf(s, "%d", &n);
            int num = 0;
            for (int i = 0; ans[i]; ++i)
                if (ans[i] > num && ans[i] <= n)
                    num = ans[i];
            printf("%d\n", num);
        }
    }
    return 0;
}