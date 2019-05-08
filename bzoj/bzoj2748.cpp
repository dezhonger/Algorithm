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

int f[51][1001];
int n, bg, mx, c;
int main() {
    cin >> n >> bg >> mx;
    f[0][bg] = 1;
    for (int i = 1; i <= n; i += 1) {
        cin >> c;
        for (int j = 0; j <= mx; j += 1)
            if (f[i - 1][j]) {
                if (j + c <= mx) f[i][j + c] = 1;
                if (j - c >= 0) f[i][j - c] = 1;
            }
    }
    int ans = -1;
    for (int i = mx; i >= 0; i--)
        if (f[n][i]) {
            ans = i;
            break;
        }
    cout << ans << endl;
    return 0;
}
