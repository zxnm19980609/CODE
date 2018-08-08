#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int INF = 0x3F3F3F3F;
const int MAX = 550;
int n, m, k, dis[MAX][MAX];
char s[MAX];
bool g[MAX][MAX], vis[MAX][MAX];
queue<pair<int, int> > q;
bool valid(int x, int y) {
    return x && x <= n && y && y <= m;
}
int bfs(int startTime) {
    memset(dis, 0x3F, sizeof dis);
    memset(vis, 0, sizeof vis);
    while (!q.empty()) q.pop();
    dis[1][1] = startTime;
    q.push(make_pair(1, 1));
    vis[1][1] = true;
    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (valid(nx, ny) && g[nx][ny] && !vis[nx][ny]) {
                dis[nx][ny] = dis[now.first][now.second] + 1;
                q.push(make_pair(nx, ny));
                vis[nx][ny] = true;
            }
        }
    }
    return dis[n][m];
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; ++j)
            g[i][j] = (s[j] == '.');
    }
    int Martians = bfs(-5);
    for (int x, y, i = 0; i < k; ++i) {
        scanf("%d%d", &x, &y);
        g[x + 1][y + 1] = true;
    }
    int EPFL = bfs(0);
    if (EPFL < Martians)
        puts("YES");
    else
        puts("NO");
    return 0;
}