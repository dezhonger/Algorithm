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
#include <unordered_set>
#include <unordered_map>
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

const int maxn = 200010;
int n, c[maxn];
vector< vector<int>> g;
LL color[2], dp[maxn], ans[maxn];

void dfs1 (int node, int parent) {
    dp[node] = c[node];
    for (int nxt : g[node]) {
        if (nxt == parent) continue;
        dfs1 (nxt, node);
        dp[node] += max (0LL, dp[nxt]);
    }
}

void dfs2 (int node, int parent) {

    for (int nxt : g[node]) {
        if (nxt == parent) continue;
        ans[nxt] = max (0LL, ans[node] - max (0LL, dp[nxt])) + dp[nxt];
        dfs2 (nxt, node);
    }
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    int x, y;
    cin >> n;
    g = vector<vector<int>>(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        if (c[i] == 0) c[i] = -1;
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        x--;
        y--;
        g[x].pb (y);
        g[y].pb (x);
    }
    dfs1 (0, -1);
    ans[0] = dp[0];
    dfs2 (0, -1);
    //for (int i = 0; i < n; i++) cout << i+1 << ": " << dp[i] << endl;
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
