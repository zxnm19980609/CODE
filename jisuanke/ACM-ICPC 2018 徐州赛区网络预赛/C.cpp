#include <bits/stdc++.h>
using namespace std;
int score[25];
void init() {
    score[6] = 10000;
    score[7] = 36;
    score[8] = 720;
    score[9] = 360;
    score[10] = 80;
    score[11] = 252;
    score[12] = 108;
    score[13] = 72;
    score[14] = 54;
    score[15] = 180;
    score[16] = 72;
    score[17] = 180;
    score[18] = 119;
    score[19] = 36;
    score[20] = 360;
    score[21] = 1080;
    score[22] = 144;
    score[23] = 1800;
    score[24] = 3600;
}
int main() {
    init();
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        printf("score[%d] = %d;\n", a, b);
    }
    return 0;
}