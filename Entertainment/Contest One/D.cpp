#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
string s1("CARScarsIuVEJxTXsUvOHhngyZKfAYmaqolMNtGQibwdjPrCpekFWzLaySBaPybRMgzYMynY");
string s2("UnilEPFLvpVZzBNtLSCubWmaocIYneAPqxDshRkMGgJfHrFUQTjXOwdPolyProgisawesome");
map<char, char> translator;
set<char> letters1, letters2;
char a[101000];
void init() {
    int len = s1.size();
    for (int i = 0; i < len; ++i) {
        translator.insert(make_pair(s1[i], s2[i]));
        letters1.insert(s1[i]);
        letters2.insert(s2[i]);
    }
    char ch1, ch2;
    for (char i = 'A'; i <= 'Z'; ++i)
        if (letters1.find(i) == letters1.end()) {
            ch1 = i;
            break;
        }
    for (char i = 'a'; i <= 'z'; ++i)
        if (letters1.find(i) == letters1.end()) {
            ch1 = i;
            break;
        }
    for (char i = 'A'; i <= 'Z'; ++i)
        if (letters2.find(i) == letters2.end()) {
            ch2 = i;
            break;
        }
    for (char i = 'a'; i <= 'z'; ++i)
        if (letters2.find(i) == letters2.end()) {
            ch2 = i;
            break;
        }
    translator.insert(make_pair(ch1, ch2));
}
int main() {
    // freopen("in.txt", "r", stdin);
    init();
    int n;
    scanf("%d%*c", &n);
    gets(a);
    for (int i = 0; a[i]; ++i)
        if (isalpha(a[i])) a[i] = translator[a[i]];
    puts(a);
    return 0;
}