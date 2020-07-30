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

const int maxn = 200020;
int n, a[maxn], b[maxn], c[maxn];

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);

    cin >> n;
    rep (i, 1, n) cin >> a[i];
    rep (i, 1, n) cin >> b[i];
    rep (i, 1, n) c[i] = a[i] - b[i];

    LL res = 0;

    sort (c + 1, c + 1 + n);
    int r = n;
    for (int i = 1; i < n; i++) {
        while (r - 1 > i && c[r - 1] + c[i] > 0) r--;
        if (r <= i) r = i + 1;
        if (c[r] + c[i] > 0) res += n - r + 1;
    }
    cout << res << endl;
    return 0;
}
