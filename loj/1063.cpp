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


const int maxn = 202;
int n, t[maxn], a[maxn], b[maxn], dp[maxn][maxn];

int main() {
    cin >> n;
    rep (i, 1, n) cin >> t[i];
    rep (i, 1, n) a[i] = t[i];
    rep (i, 1, n - 1) b[i] = a[i + 1];
    b[n] = a[1];
    rep (i, 1, n) a[i + n] = a[i], b[i + n] = b[i];

    CLR(dp, 0x80);
    rep(i, 1, n << 1) dp[i][i] = 0;
    rep(i, 2, n << 1) rep(j, 1, n << 1) {
        int ed = j + i - 1;
        if (ed > (n << 1)) continue;
        rep(k, j, ed - 1) {
            dp[j][ed] = max(dp[j][ed], dp[j][k] + dp[k+1][ed] + a[j] * b[k] * b[ed]);
        }
    }
    int r = 0;

    rep(i, 1, n + 1) r = max(r, dp[i][i + n -1]);
    cout << r << endl;
    return 0;
}
