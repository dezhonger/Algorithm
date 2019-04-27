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

const int maxn = 105;
int n, m, a[maxn][maxn], dp[maxn][maxn][maxn];

int main() {
    CLR (dp, 0x80);
    cin >> n >> m;
    rep (i, 1, n) rep (j, 1, m) cin >> a[i][j];
    dp[2][1][1] = 0;
    int s = n + m;
    rep (i, 3, s - 1) rep (j, 1, n) rep (k, 1, n) {
        cout << s << " "<< j << " " << k << endl;
        if (j == k) continue;
        int j1 = i - j;
        int k1 = i - k;
        if (j1 <= 0 || k1 <= 0 || j1 > m || k1 > m) continue;

        dp[i][j][k] = max (dp[i][j][k], dp[i - 1][j - 1][k] + a[j][j1] + a[k][k1]);
        dp[i][j][k] = max (dp[i][j][k], dp[i - 1][j][k - 1]+ a[j][j1] + a[k][k1]);
        dp[i][j][k] = max (dp[i][j][k], dp[i - 1][j][k]+ a[j][j1] + a[k][k1]);
        dp[i][j][k] = max (dp[i][j][k], dp[i - 1][j -1][k - 1]+ a[j][j1] + a[k][k1]);

    }


    cout << max (dp[s - 1][n - 1][n], dp[s - 1][n][n - 1]) << endl;
    return 0;
}
