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

const int maxn = 2020;

struct Node {
    int u;
    int depth;
} node[maxn];

int ver[maxn], head[maxn], nxt[maxn];
int n, dp[maxn], fa[maxn];
int tot = 0;

//添加边
void add (int x, int y) {
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

int cmp (const Node& a, const Node& b) {
    return a.depth > b.depth;
}

//顶点是vertex， vertex的父节点是father
void dfs (int vertex, int father) {
    for (int i = head[vertex]; i; i = nxt[i]) {
        int y = ver[i];
        //continue掉父节点
        if (y == father) continue;
        node[y].u = y;
        fa[y] = vertex;
        node[y].depth = node[vertex].depth + 1;
        dfs (y, vertex);
    }
}

void update(int vertex) {
    for (int i = head[vertex]; i; i = nxt[i]) {
        int y = ver[i];
        if (dp[y] < dp[vertex] - 1) {
            dp[y] = dp[vertex] - 1;
            if (dp[y] > 0) update(y);
        }
    }
}


int main() {
    int tmp;
    cin >> n;
    for (int i = 2; i <= n ; i++) {
        cin >> tmp;
        add (i, tmp);
        add (tmp, i);
    }
    //以顶点1为树根，dfs，求个每个顶点的depth
    fa[1] = 1;
    node[1].depth = 1;
    node[1].u = 1;
    dfs (1, 1);
    //for (int i = 1; i <= n; i++) cout << node[i].u << " " << node[i].depth << " " << fa[node[i].u] << endl;
    sort (node + 1, node + 1 + n, cmp);
    CLR (dp, -1);
    int ans = 0;
    //爷爷节点
    int k = 2;
    for (int i = 1; i <= n ; i++) {
        int u = node[i].u;
        if (dp[u] == -1) {
            ans++;
            //找到爷爷节点
            for (int j = 1; j <= k; j++) u = fa[u];
            dp[u] = k;
            update(u);
        }
    }
    cout << ans;
    return 0;
}
