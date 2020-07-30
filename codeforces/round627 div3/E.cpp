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

const int maxn = 2010;
int f[maxn][maxn], a[maxn];
int n, h, l, r;

int main() {
	ios::sync_with_stdio (false);
    cin.tie (0);
    cin >> n >> h >> l >> r;
    rep(i, 1, n) cin >> a[i];
    CLR(f, 0x80);
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < h; j++) {
            int add = 0;
            if (j >= l && j <= r) add = 1;
            int last1 = (j - a[i] + h) % h;
            int last2 = (j - a[i] + 1 + h) % h;
            f[i][j] = max(f[i-1][last1] + add, f[i-1][last2] + add);
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++) ans = max(ans, f[n][i]);
    cout << ans << endl;
    return 0;
}
