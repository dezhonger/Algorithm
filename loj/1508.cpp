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

int n, m, a[220][220], f[220][220], v[220][220];

int main() {
    cin >> n >> m;
    int i, j;
    rep (i, 1, n) rep (j, 1, m) cin >> a[i][j];
    memset (f, 0x80, sizeof (f));
    f[n][m / 2 + 1] = a[n][m / 2 + 1];
    v[n][m / 2 + 1] = 1;
    f[n][m / 2] = a[n][m / 2];
    v[n][m / 2] = 1;
    f[n][m / 2 + 2] = a[n][m / 2 + 2];
    v[n][m / 2 + 2] = 1;
    for (int i = n; i > 1; i--) {
        for (int j = 1; j <= m ; j++) {
            if (v[i][j]) {
                v[i - 1][j] = 1;
                f[i - 1][j] = max (a[i - 1][j] + f[i][j], f[i - 1][j]);
                if (j - 1 > 0) {
                    v[i - 1][j - 1] = 1;
                    f[i - 1][j - 1] = max (a[i - 1][j - 1] + f[i][j], f[i - 1][j - 1]);
                }
                if (j + 1 <= m) {
                    v[i - 1][j + 1] = 1;
                    f[i - 1][j + 1] = max (a[i - 1][j + 1] + f[i][j], f[i - 1][j + 1]);
                }
            }
        }
    }
//    rep (i, 1, n) rep (j, 1, m) cout << i << " " << j << " " << f[i][j] << endl;
    int r = 0x80000000;
    for (int j = 1; j <= m ; j++) r = max (r, f[1][j]);
    cout << r << endl;
    return 0;
}
