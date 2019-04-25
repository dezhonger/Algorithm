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


const int maxn = 300005;
int i, n, x;
LL a[maxn];


//dp[i][0]: 以第i个数字结尾的都没乘x的最大值
//dp[i][1]: 以第i个数字结尾的并且乘以x的最大值
//dp[i][1]: 以第i个数字结尾的并且之前有个区间已经乘以x的最大值

LL dp[maxn][3];

int main() {
    cin >> n >> x;
    rep (i, 1, n) cin >> a[i];
    LL r = 0;
    rep (i, 1, n) {
        dp[i][0] = max (a[i], dp[i - 1][0] + a[i]);
        dp[i][1] = max (a[i] * x, max (dp[i - 1][1] + a[i] * x, dp[i - 1][0] + a[i] * x));
        dp[i][2] = max (dp[i - 1][1] + a[i], dp[i - 1][2] + a[i]);
        r = max (r, dp[i][0]);
        r = max (r, dp[i][1]);
        r = max (r, dp[i][2]);
    }
    cout << r << endl;
    return 0;
}
