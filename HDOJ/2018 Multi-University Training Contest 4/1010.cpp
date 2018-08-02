#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int row[16][4], col[16][4], ans;
bool checkRow(int blockRow) {
    int s = blockRow * 4;
    for (int i = 0; i < 4; ++i)
        if ((row[s][i] | row[s + 1][i] | row[s + 2][i] | row[s + 3][i]) != 0xFFFF)
            return false;
    return true;
}
bool checkCol() {
    for (int s = 0; s < 4; ++s)
        for (int j = 0; j < 4; ++j) {
            if ((col[s][j] | col[s + 4][j] | col[s + 8][j] | col[s + 12][j]) != 0xFFFF)
                return false;
    }
    return true;
}
void rot(int b, int tim) {
    int temp[4];
    if (tim < 0) tim += 4;
    for (int k = 0; k < tim; ++k) {
        for (int i = 0; i < 4; ++i)
            temp[i] = row[b][i];
        for (int i = 0; i < 4; ++i)
            row[b][i] = col[b][i];
        for (int i = 0; i < 4; ++i)
            col[b][i] = temp[3 - i];
    }
}
void dfs(int id, int step) {
    if (id == 16) {
        if (!checkRow(id / 4 - 1)) return;
        if (checkCol()) ans = min(ans, step);
        return;
    }
    if (id % 4 == 0 && id / 4 > 0 && !checkRow(id / 4 - 1))
        return;
    for (int i = 0; i < 4; ++i) {
        rot(id, i);
        dfs(id + 1, step + i);
        rot(id, -i);
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        ans = 0x3F3F3F3F;
        char c;
        for (int i = 0; i < 16; ++i)
            for (int j = 0; j < 16; ++j) {
                scanf(" %c", &c);
                int shift;
                if (c >= '0' && c <= '9')
                    shift = c - '0';
                else
                    shift = 10 + c - 'A';
                int b = i / 4 * 4 + j / 4;
                row[b][i % 4] |= (1 << shift);
                col[b][j % 4] |= (1 << shift);
            }
        dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}