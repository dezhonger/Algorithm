#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define reps(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back
#define ps push
#define mp make_pair
#define CLR(x,t) memset(x,t,sizeof x)
#define LEN(X) strlen(X)
#define F first
#define S second
#define Debug(x) cout<<#x<<"="<<x<<endl;


const double euler_r = 0.57721566490153286060651209;
const double pi = 3.141592653589793238462643383279;
const double E = 2.7182818284590452353602874713526;
const int inf = ~0U >> 1;
const int MOD = int (1e9) + 7;
const double EPS = 1e-6;

typedef long long LL;


//求树上两点间距离
//dist(x, y) = dist(x) + dist(y) - 2dist(lca(x, y))
const int  SIZE = 50010;
int f[SIZE][20], d[SIZE], dist[SIZE];
int ver[2 * SIZE], Next[SIZE], edge[2 * SIZE], head[SIZE];
int T, n, m, tot, t;

queue<int> q;
void add (int x, int y, int z) {
    ver[++tot] = y;
    edge[tot] = z;
    Next[tot] = head[x];
    head[x] = tot;
}

void bfs() {
    q.push (1);
    //深度
    d[1] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i];
            if (d[y]) continue;
            d[y] = d[x] + 1;
            dist[y] = dist[x] + edge[i];
            f[y][0] = x;
            for (int j = 1; j <= t; j++) f[y][j] = f[f[y][j - 1]][j - 1];
            q.push (y);
        }
    }
}

int lca (int x, int y) {
    if (d[x] > d[y]) swap (x, y);
    for (int i = t; i >= 0; i--) if (d[f[y][i]] >= d[x]) y = f[y][i];
    if (x == y) return x;
    for (int i = t; i >= 0; i--) if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        t = (int) (log (n) / log (2)) + 1;
        //init
        for (int i = 1; i <= n ; i++) head[i] = d[i] = 0;
        tot = 0;

        for (int i = 1; i < n ; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            add (x, y, z);
            add (y, x, z);
        }
        bfs();
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            int lcaNode = lca(x, y);
            cout << dist[x] + dist[y] - 2 * dist[lcaNode] << endl;
        }
        cout << endl;

    }

    return 0;
}
