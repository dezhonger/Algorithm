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

int gcd (int a, int b) {
    return b == 0 ? a : gcd (b, a % b);
}

const int maxn = 200010;
int dfn[maxn], sz[maxn], fa[maxn], dep[maxn];
vector<int> g[maxn];
int tmp[maxn];
int tme = 0, tot = 1;
int n, m, k;


void dfs (int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u] = f;
    sz[u] = 1;
    dfn[u] = ++tme;
    for (int y : g[u]) {
        if (y == f) continue;
        dfs(y, u);
        sz[u] += sz[y];
    }

}

bool cmp (int x, int y) {
    return dep[x] < dep[y];
}

bool in (int x, int y) {
    return dfn[x] <= dfn[y] && dfn[y] < dfn[x] + sz[x];
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);

    cin >> n >> m;
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        //add (u, v);
        //add (v, u);
    }
    dfs (1, 1);
    while (m--) {
        cin >> k;
        for (int i = 1; i <= k; i++)
            cin >> tmp[i];
        sort (tmp + 1, tmp + k + 1, cmp);
        bool fg = true;

        for (int i = 1; fg && i < k; i++) {
            if (!in (fa[tmp[i]], fa[tmp[i + 1]]))
                fg = false;
        }
        cout << (fg ? "YES" : "NO") << endl;
    }
    return 0;
}
