#include <cstdio>
#include <cstring>
using namespace std;
const int OP = 0;
const int FZ = 1;
const int NFZ = 2;
const int NZ = 3;
int len, last;
char a[550];
inline void im() {
    printf("IMPOSSIBLE\n");
}
inline bool isOp(char ch) {
    return ch == '+' || ch == '*';
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", a);
        len = strlen(a);
        last = OP;
        bool flag = true;
        for (int i = 0; i < len; ++i) {
            if (a[i] == '?') {
                switch (last) {
                    case OP:
                    case NFZ:
                    case NZ:
                        a[i] = '1';
                        last = NZ;
                        break;
                    case FZ:
                        a[i] = '+';
                        last = OP;
                        break;
                }
            }
            else {
                switch (last) {
                    case OP:
                        if (isOp(a[i])) {
                            flag = false;
                            im();
                        }
                        else if (a[i] == '0')
                            last = FZ;
                        else
                            last = NZ;
                        break;
                    case FZ:
                        if (!isOp(a[i])) {
                            flag = false;
                            im();
                        }
                        else
                            last = OP;
                        break;
                    case NFZ:
                    case NZ:
                        if (isOp(a[i]))
                            last = OP;
                        else if (a[i] == '0')
                            last = NFZ;
                        else
                            last = NZ;
                }
            }
            if (!flag) break;
        }
        if (flag && last == OP) {
            flag = false;
            im();
        }
        if (flag) printf("%s\n", a);
    }
    return 0;
}