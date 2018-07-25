#include <cstdio>
using namespace std;
const int DAY = 24 * 60;
int main() {
    // freopen("in.txt", "r", stdin);
    int T, a, b;
    char str[10];
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%s", &a, &b, str);
        int sign = (str[3] == '+' ? 1 : -1);
        double xy;
        sscanf(str + 4, "%lf", &xy);
        int x = sign * (int)(xy + 0.05);
        int y = sign * (int)(xy * 10 + 0.05) % 10;
        int now = a * 60 + b - 8 * 60;
        now = (now + DAY) % DAY;
        now = now + x * 60 + y * 6;
        now = (now + DAY) % DAY;
        printf("%02d:%02d\n", now / 60, now % 60);
    }
    return 0;
}
