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
#define gc getchar

const double euler_r = 0.57721566490153286060651209;
const double pi = 3.141592653589793238462643383279;
const double E = 2.7182818284590452353602874713526;
const int inf = ~0U >> 1;
const int MOD = 20180718;
const double EPS = 1e-6;

typedef long long LL;

const int N = 500050;
int n, m, cnt, a[N];
LL Ans[N], product[N];

struct Node {
    int x, y, id;
} node[N];

bool cmp (Node node1, Node node2) {
    return node1.y < node2.y;
}

inline int read() {
    int ret = 0, f = 0;
    char c = gc();
    while (!isdigit (c)) {
        if (c == '-') f = 1;
        c = gc();
    }
    while (isdigit (c)) {
        ret = ret * 10 + c - 48;
        c = gc();
    }
    if (f) return -ret;
    return ret;
}

int main() {
    n = read();
    m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    int k = sqrt (n);
    int x, y;
    for (int i = 1; i <= m; i++) {
        x = read();
        y = read();
        if (y > k) {
            int ans = 1;
            while (x <= n) {
                ans *= a[x] % MOD;
                x += y;
            }
            Ans[i] = ans;
        } else if (y == 0) {
            Ans[i] = a[x];
        } else {
            node[++cnt].x = x;
            node[cnt].y = y;
            node[cnt].id = i;
        }
    }
    sort (node + 1, node + 1 + cnt, cmp);
    for (int i = 1; i <= cnt; i++) {
        if (i == 1 || node[i].y != node[i - 1].y) {
            for (int j = 1; j <= n; j++) product[j] = 1;
            for (int j = n; j > n - node[i].y; j--) product[j] = a[j];
            for (int j = n - node[i].y; j >= 1; j--) {
                int last = product[j + node[i].y];
                product[j] = 1LL * a[j] * last % MOD;
            }
        }
        Ans[node[i].id] = product[node[i].x];
    }

    for (int i = 1; i <= m; i++) printf ("%lld\n", Ans[i]);
    return 0;
}
