#include <cmath>
#include <stack>
#include <algorithm>
#include <string>
#include <deque>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <queue>
#include <cstdlib>
#include <iomanip>
using namespace std;

#define rep(i, a, b) for( i = (a); i <= (b); i++)
#define rrep(i, a, b) for( i = (a); i >= (b); i--)
#define reps(i, a, b) for( i = (a); i < (b); i++)
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

const int maxn = 2505;
int a[maxn][maxn];
int zerozuo[maxn][maxn], zeroyou[maxn][maxn], zeroshang[maxn][maxn];
int dp[maxn][maxn];
int m, n;

int main() {
    cin >> m >> n;
    int i, j, r;
    r = 0;
    rep (i, 1, m) rep (j, 1, n) cin >> a[i][j];
    rep (i, 1, m) rep (j, 1, n) {
        if (a[i][j] == 1) zerozuo[i][j] = zeroshang[i][j] = 0;
        else {
            zerozuo[i][j] = zerozuo[i][j-1] + 1;
            zeroshang[i][j] = zeroshang[i-1][j] + 1;
        }
    }
    rep(i, 1, m) rrep(j, n, 1) {
        if (a[i][j] == 1) zeroyou[i][j] = 0;
        else zeroyou[i][j] = zeroyou[i][j+1] + 1;
    }

//    rep (i, 1, m) rep (j, 1, n) {
//        if (a[i][j] == 0) one1[i][j] = 0;
//        else {
//            one1[i][j] = min (zeroshang[i - 1][j], zerozuo[i][j - 1]);
//            one2[i][j] = min (zeroshang[i - 1][j], zeroyou[i][j + 1]);
//        }
//    }

    rep (i, 1, m) rep (j, 1, n) {
        if (a[i][j] == 0) dp[i][j] = 0;
        else dp[i][j] = min (dp[i - 1][j - 1], min (zeroshang[i - 1][j], zerozuo[i][j - 1])) + 1;
        r = max(r, dp[i][j]);
    }

    CLR(dp, 0);

    rep(i, 1, m) rrep(j, n, 1) {
        if (a[i][j] == 0) dp[i][j] = 0;
        else dp[i][j] = min (dp[i - 1][j + 1], min (zeroshang[i - 1][j], zeroyou[i][j + 1])) + 1;
        r = max(r, dp[i][j]);
    }

    cout << r << endl;
    return 0;
}
