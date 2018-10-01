#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const double EPS = 1e-8;
class Edge {
public:
    double w;
    int to, next;
}edge[(MAXN * MAXN) << 1];
int cnt, h[MAXN];
int n, St, Ed, A, B, C1, C2;
int x[MAXN], y[MAXN], r[MAXN];
bool vis[MAXN];
double dis[MAXN];
queue<int> que;
double calcLC(double A, double B, double C, double X, double Y, double R) {
    double dist = fabs(A * X + B * Y + C) / sqrt(A * A + B * B) - R;
    return dist < EPS ? 0 : dist;
}
double calcCC(double X1, double Y1, double R1, double X2, double Y2, double R2) {
    double dist = sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2)) - R1 - R2;
    return dist < EPS ? 0 : dist;
}
void addEdge(int u, int v, double w) {
    edge[cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = h[u];
    h[u] = cnt++;
    swap(u, v);
    edge[cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = h[u];
    h[u] = cnt++;
}
double SPFA() {
    for (int i = 1; i <= Ed; ++i) dis[i] = fabs(C1 - C2);
    dis[St] = 0.0;
    vis[St] = true;
    que.push(St);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for (int p = h[u]; ~p; p = edge[p].next) {
            int v = edge[p].to;
            if (dis[v] > dis[u] + edge[p].w) {
                dis[v] = dis[u] + edge[p].w;
                if (!vis[v]) {
                    que.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return dis[Ed];
}
int main() {
    scanf("%d%d%d%d%d", &n, &A, &B, &C1, &C2);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d", &x[i], &y[i], &r[i]);
    St = n + 1;
    Ed = n + 2;
    cnt = 0;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; ++i)
        addEdge(St, i, calcLC(A, B, C1, x[i], y[i], r[i]));
    for (int i = 1; i <= n; ++i)
        addEdge(i, Ed, calcLC(A, B, C2, x[i], y[i], r[i]));
    if (A == 0 || B == 0)
        addEdge(St, Ed, fabs(C1 - C2));
    else
        addEdge(St, Ed, calcLC(A, B, C1, 0, -C2 / (double)B, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            addEdge(i, j, calcCC(x[i], y[i], r[i], x[j], y[j], r[j]));
    printf("%.8f\n", SPFA());
    return 0;
}