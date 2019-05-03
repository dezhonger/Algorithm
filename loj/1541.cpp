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


int n, m;
int a[360];
int c[5];
const int maxn = 42;
int f[maxn][maxn][maxn][maxn];

int main() {
    cin >> n >> m;
    int x;
    rep (i, 1, n) cin >> a[i];
    rep (i, 1, m) cin >> x, c[x]++;
    CLR (f, 0);
    f[0][0][0][0] = a[1];
    rep (i, 0, c[1]) rep (j, 0, c[2]) rep (k, 0, c[3]) rep (o, 0, c[4]) {
        int tmp = i * 1 + j * 2 + k * 3 + o * 4 + 1;
        if (i) f[i][j][k][o] = max (f[i][j][k][o], f[i - 1][j][k][o] + a[tmp]);
        if (j) f[i][j][k][o] = max (f[i][j][k][o], f[i][j - 1][k][o] + a[tmp]);
        if (k) f[i][j][k][o] = max (f[i][j][k][o], f[i][j][k - 1][o] + a[tmp]);
        if (o) f[i][j][k][o] = max (f[i][j][k][o], f[i][j][k][o - 1] + a[tmp]);
    }
    cout << f[c[1]][c[2]][c[3]][c[4]] << endl;
    return 0;
}
