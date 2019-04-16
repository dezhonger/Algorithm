#include<set>
#include<map>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf 1000000000
#define pa pair<int,int>
#define ll long long
#define mod 1000000007
using namespace std;
#define p(i,j) (i-1)*m+j

int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int n, m;
int xx[4] = {0, 0, 1, -1}, yy[4] = {1, -1, 0, 0};
int a[705][705], f[705][705];
bool forb[705][705];
void change (int x, int y, int val) {
    a[x][y] = val;
}
void mark (int a, int b, int c, int d, bool f) {
    for (int i = a; i <= b; i++)
        for (int j = c; j <= d; j++)
            forb[i][j] = f;
}
int dp (int x, int y) {
    if (forb[x][y]) return -inf;
    if (f[x][y] != -1) return f[x][y];
    f[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int tx = x + xx[i], ty = y + yy[i];
        if (tx < 1 || ty < 1 || tx > n || ty > n) continue;
        if (a[x][y] > a[tx][ty]) f[x][y] = max (f[x][y], dp (tx, ty) + 1);
    }
    return f[x][y];
}
int main() {
    n = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = read();
    int a, b, c, d;
    m = read();
    while (m--) {
        char ch[2];
        scanf ("%s", ch + 1);
        if (ch[1] != 'Q') {
            a = read();
            b = read();
            c = read();
        }
        if (ch[1] == 'C') change (a, b, c);
        if (ch[1] == 'B') d = read(), mark (a, c, b, d, 0);
        if (ch[1] == 'S') d = read(), mark (a, c, b, d, 1);
        if (ch[1] == 'Q') {
            int mx = 0;
            memset (f, -1, sizeof (f));
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    mx = max (mx, dp (j, k));
            printf ("%d\n", mx);
        }
    }
    return 0;
}
