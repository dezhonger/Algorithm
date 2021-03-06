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
    int a[110];
    int dp1[110];
    int dp2[110];
    int n;
    cin >> n;
    for (int i = 1; i <= n ; i++) cin >> a[i];
    for (int i = 1; i <= n ; i++) {
        dp1[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) dp1[i] = max (dp1[i], dp1[j] + 1);
            if (a[j] > a[i]) dp2[i] = max (dp2[i], dp2[j] + 1);
        }
    }
    for (int i = n; i >= 1; i--) {
        dp2[i] = 1;
        for (int j = n; j > i; j--) {
            if (a[j] < a[i]) dp2[i] = max (dp2[i], dp2[j] + 1);
        }
    }
    int ma = -1;
    for (int i = 1; i <= n ; i++) {
        ma = max (ma, dp1[i] + dp2[i] - 1);
    }
    cout << n - ma << endl;
    return 0;
}
