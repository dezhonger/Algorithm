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

int n, m, k;
const int maxn = 801;
int dp[maxn][maxn][20][2];
int a[maxn][maxn];

int main() {
    cin >> n >> m >> k;
    k++;
    rep (i, 1, n) rep (j, 1, m) cin >> a[i][j], dp[i][j][a[i][j] % k][0] = 1;
    int ans = 0;
    rep (i, 1, n) rep (j, 1, m) rep (h, 0, k) {
        int h1 = (h - a[i][j] + k) % k;
        int h2 = (h + a[i][j] + k) % k;
        dp[i][j][h][0] += dp[i - 1][j][h1][1];
        dp[i][j][h][0] %= MOD;
        dp[i][j][h][0] += dp[i][j - 1][h1][1];
        dp[i][j][h][0] %= MOD;
        dp[i][j][h][1] += dp[i - 1][j][h2][0];
        dp[i][j][h][1] %= MOD;
        dp[i][j][h][1] += dp[i][j - 1][h2][0];
        dp[i][j][h][1] %= MOD;
    }
    rep(i, 1, n) rep(j, 1, m) ans += dp[i][j][0][1], ans %= MOD;
    cout << ans << endl;
    return 0;
}
