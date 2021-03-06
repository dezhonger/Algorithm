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

const int maxn = 300010;
int n, k;
LL a[maxn];
LL s[maxn];
int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];


    s[0] = 0;
    int j = 1;
    for (int i = n; i >= 1; i--) {
        s[j] = s[j-1] + a[i];
        j++;
    }
    LL ans = 0;
    ans += s[n];
    sort(s + 1, s + n);
    for (int i = n - 1; i > n - 1 - (k - 1); i--) ans += s[i];
    cout << ans << endl;
    return 0;
}
