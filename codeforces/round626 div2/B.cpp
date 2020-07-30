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

int n, m, k, t;
vector<int> r, c;

LL cal (int a, int b) {
    int rc = 0, cc = 0;
    for (int i = a; i <= n; i++) {
        if (r[i] == r[i-a] + a) rc++;
    }

    for (int i = b; i <= m; i++) {
        if (c[i] == c[i-b] + b) cc++;
    }
    return (LL)rc * cc;
}


int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cin >> n >> m >> k;
    r.resize(n + 1);
    c.resize(m + 1);

    r[0] = c[0] = 0;

    rep (i, 1, n) cin >> r[i], r[i] += r[i - 1];
    rep (i, 1, m) cin >> c[i], c[i] += c[i - 1];


    LL res = 0;
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) res += cal(i, k / i);
    }
    cout << res << endl;
    return 0;
}
