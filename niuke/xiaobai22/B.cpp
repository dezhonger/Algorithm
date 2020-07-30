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
#define Debug(x) cout<<#x<<"="<<x<<endl;


const double euler_r = 0.57721566490153286060651209;
const double pi = 3.141592653589793238462643383279;
const double E = 2.7182818284590452353602874713526;
const int inf = ~0U >> 1;
const int MOD = int (1e9) + 7;
const double EPS = 1e-6;

typedef long long LL;


const int MAXN = 200005;
int head[MAXN];
int ver[MAXN];
int nxt[MAXN];
int val[MAXN];
int tot;

//以该点为根节点的最大值
int dp[MAXN];
LL result = -10000000;
//加入有向边(x, y), 权值为z
void add (int x, int y) {
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

//访问从x出发的所有边

LL dfs (int node, int pa) {
    LL ma1 = 0, ma2 = 0;
    LL ma = 0;
    for (int i = head[node]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == pa) continue;
        LL resY = dfs (y, node);
        ma = max (ma, resY);
        if (resY >= ma1) ma2 = ma1, ma1 = resY;
        else if (resY >= ma2) ma2 = resY;
        result = max (result, val[node] + ma1 + ma2);
    }

    result = max (result, val[node] + ma);
    return max ( (LL) val[node], val[node] + ma);
}



int main() {
    int n;
    tot = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> val[i], result = max (result, (LL) val[i]);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        add (x, y);
        add (y, x);
    }

    dfs (0, -1);
    cout << result << endl;
    return 0;
}
