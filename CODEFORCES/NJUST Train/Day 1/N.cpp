#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;
set<string> ans;
char s[1005];
bool vis[30];
int main() {
    // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        memset(vis, 0, sizeof vis);
        for (int j = 0; s[j]; ++j)
            vis[s[j] - 'a'] = true;
        string ins("");
        for (char ch = 'a'; ch <= 'z'; ++ch)
            if (vis[ch - 'a'])
                ins.append(1, ch);
        ans.insert(ins);
    }
    printf("%d\n", (int)ans.size());
    return 0;
}