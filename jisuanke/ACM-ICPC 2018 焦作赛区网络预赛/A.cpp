#include <bits/stdc++.h>
using namespace std;
char s[20];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        for (int i = 0; s[i]; ++i)
            s[i] = tolower(s[i]);
        if (strcmp(s, "jessie") == 0)
            puts("Good guy!");
        else
            puts("Dare you say that again?");
    }
    return 0;
}