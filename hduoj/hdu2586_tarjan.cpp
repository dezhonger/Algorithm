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


//tarjan算法求lca
const int  SIZE = 50010;
int ver[2 * SIZE], Next[2 * SIZE], edge[2 * SIZE], head[SIZE];
int fa[SIZE], d[SIZE], v[SIZE], lca[SIZE], ans[SIZE];
vector<int> query[SIZE], query_id[SIZE];
int T, n, m, tot, t;

void add (int x, int y, int z) {
    ver[++tot] = y;
    edge[tot] = z;
    Next[tot] = head[x];
    head[x] = tot;
}

void add_query(int x, int y, int id) {
    query[x].push_back(y), query_id[x].push_back(id);
    query[y].push_back(x), query_id[y].push_back(id);
}

int get(int x) {
    if (x == fa[x]) return x;
    return fa[x] = get(fa[x]);
}

void tarjan(int x) {
    v[x] = 1;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (v[y]) continue;
        d[y] = d[x] + edge[i];
        tarjan(y);
        fa[y] = x;
    }
    for (int i = 0; i < query[x].size(); i++) {
        int y = query[x][i], id = query_id[x][i];
        if (v[y] == 2) {
            //这里求出了lca(x, y)
            int lca = get(y);
            ans[id] = min(ans[id], d[x] + d[y] - 2 * d[lca]);
        }
    }
    v[x] = 2;
}



int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n ; i++) {
            head[i] = 0;
            fa[i] = i;
            v[i] = 0;
            query[i].clear();
            query_id[i].clear();
        }
        tot = 0;

        for (int i = 1; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            add (x, y, z);
            add (y, x, z);
        }
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            if (x == y) ans[i] = 0;
            else {
                add_query(x, y, i);
                ans[i] = 1 << 30;
            }
        }
        tarjan(1);
        for (int i = 1; i <= m; i++) cout << ans[i] << endl;
    }

    return 0;
}
