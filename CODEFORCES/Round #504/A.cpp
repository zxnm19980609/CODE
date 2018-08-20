#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string s, t;
int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int n, m, p;
    cin >> n >> m >> s >> t;
    if ((p = s.find('*')) == string::npos) {
        if (s.compare(t) == 0)
            puts("YES");
        else
            puts("NO");
    }
    else {
        if (n - 1 > m)
            puts("NO");
        else {
            string pres = s.substr(p + 1);
            string pret = t.substr(t.length() - (s.length() - p - 1));
            string sufs = s.substr(0, p);
            string suft = t.substr(0, p);
            if (pres.compare(pret) == 0 && sufs.compare(suft) == 0)
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}