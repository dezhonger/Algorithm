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
int n, a[maxn], s[maxn];
int dpma[maxn][maxn];
int dpmi[maxn][maxn];

int main() {
    cin >> n;
    CLR (dpma, 0x80);
    CLR (dpmi, 0x7f);
    rep (i, 1, n) cin >> a[i], a[i + n] = a[i];
    rep (i, 1, n << 1) s[i] = s[i - 1] + a[i];
    rep (i, 1, (n << 1)) dpma[i][i] = dpmi[i][i] = 0;
    rep (i, 2, (n << 1)) rep (j, 1, (n << 1)) {
        int ed = j + i - 1;
        if (ed > (n << 1)) break;
        for (int k = j; k < ed; k++) {
            dpma[j][ed] = max (dpma[j][ed], dpma[j][k] + dpma[k + 1][ed] + s[ed] - s[j - 1]);
            dpmi[j][ed] = min (dpmi[j][ed], dpmi[j][k] + dpmi[k + 1][ed] + s[ed] - s[j - 1]);
        }
    }
    int rmin = 0x7f7f7f7f;
    int rmax = 0x80000000;
    rep (i, 1, n + 1) rmin = min (rmin, dpmi[i][i + n - 1]), rmax = max (rmax, dpma[i][i + n - 1]);
    cout << rmin << endl;
    cout << rmax << endl;
    return 0;
}
