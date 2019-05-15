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
const int maxn = 100010;
int n, m;
int a[maxn], b[maxn];

int main() {
    cin >> n >> m;
    rep (i, 1, n) cin >> a[i];
    rep (i, 1, m) cin >> b[i];
    sort (a + 1, a + 1 + n);
    sort (b + 1, b + 1 + m);
    if (b[1] < a[n])
        cout << -1 << endl;
    else {

        long r = 0;
        rep (i, 1, n) r = r + 1L * a[i] * m;
        rep(i, 2, m) r += b[i] - a[n];
        if (b[1] > a[n])r += (b[1] - a[n - 1]);
        cout << r << endl;
    }
    return 0;
}
