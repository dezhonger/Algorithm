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
    int maxn = 105;
    int f[maxn][maxn];
    int a[maxn][maxn];
    int r = 0, m, n;
    CLR (f, 0);
    cin >> m >> n;
    for (int i = 1; i <= m ; i++) {
        for (int j = 1; j <= n ; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) f[i][j] = 0;
            else {
                f[i][j] = min(min(f[i-1][j], f[i][j-1]), f[i-1][j-1]) + 1;
            }
            r = max(r, f[i][j]);
        }
    }
    cout << r << endl;
    return 0;
}
