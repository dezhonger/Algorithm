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


int n;

LL f[1001][1001][2];

LL dfs (int x, int y, int c) {
    if (f[x][y][c] != -1) {
        return f[x][y][c];
    }
    LL res;
    if (c == 0) {
        //not chioce
        LL ma = 0;
        LL xuan1, xuan2, buxuan1, buxuan2;
        xuan1 = xuan2 = buxuan1 = buxuan2 = 0;
        if (x - 1 >= 0) {
            xuan1 = 1 + dfs (x - 1, y, 1 - c);
            buxuan1 = dfs (x - 1, y, c);
        }
        if (y - 1 >= x) {
            xuan2 = 1 + dfs (x, y - 1, 1 - c);
            buxuan2 = dfs (x, y - 1, c);
        }
        xuan1 %= MOD;
        xuan2 %= MOD;
        buxuan1 %= MOD;
        buxuan2 %= MOD;
        ma =  max (xuan1 + buxuan2, ma);
        ma =  max (xuan2 + buxuan1, ma);
        ma =  max (buxuan1 + buxuan2, ma);
        if (x - 1 >= 0) ma = max (ma, 1 + dfs (x - 1, y, 1 - c));
        if (y - 1 >= x) ma = max (ma, 1 + dfs (x, y - 1, 1 - c));
        res = ma;
    } else {
        LL r = 0;
        if (x - 1 >= 0) r += dfs (x - 1, y, 1 - c);
        r %= MOD;
        if (y - 1 >= x) r += dfs (x, y - 1, 1 - c);
        r %= MOD;
        res = r;
    }
//    cout << x << y << c << " " << res << endl;
//    cout << x << " " << y << " " << res << endl;
    res %= MOD;
    f[x][y][c] = res;
    return res;
}

int main() {
    cin >> n;
    CLR (f, -1);
//    int r =dfs(1, 3, 0);
    LL r = dfs (n, n, 0);
    cout << r << endl;
    return 0;
}
