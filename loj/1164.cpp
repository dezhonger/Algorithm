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

int main() {
    int n, m;
    cin >> n >> m;
    int dp[10001];
    CLR (dp, -1);
    dp[0] = 1;
    int x;
    for (int i = 1; i <= n ; i++) {
        cin >> x;
        for (int j = m; j >= x; j--) {
            if (dp[j - x] > 0) {
                if (dp[j] > 0) {
                    dp[j] += dp[j - x];
                } else {
                    dp[j] = dp[j - x];
                }
            }
        }
    }
    int r = dp[m];
    if (r < 0) r = 0;
    cout << dp[m] << endl;
    return 0;
}
