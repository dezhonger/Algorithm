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

const int maxn = 555;

int n, a[maxn], dp[maxn][maxn], f[maxn][maxn];

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    CLR(dp, 0x7f);
    for (int i = 1; i <= n ; i++) {
        dp[i][i] = 1;
        f[i][i] = a[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                if (dp[i][k] == 1 && dp[k+1][j] == 1 && f[i][k] == f[k+1][j]) {
                    dp[i][j] = 1;
                    f[i][j] = f[i][k] + 1;
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}
