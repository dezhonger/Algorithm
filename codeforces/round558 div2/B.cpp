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

const int N = 1e5 + 10;

int n, color, ans, mx, f[N], cnt[N];

int main() {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &color);
        cnt[f[color]]--;
        f[color]++;
        cnt[f[color]]++;
        mx = max (mx, f[color]);
        bool ok = false;
        if (cnt[1] == i) // every color has occurence of 1
            ok = true;
        else if (cnt[i] == 1) // only one color has the maximum occurence and the occurence is i
            ok = true;
        else if (cnt[1] == 1 && cnt[mx] * mx == i - 1) // one color has occurence of 1 and other colors have the same occurence
            ok = true;
        else if (cnt[mx - 1] * (mx - 1) == i - mx && cnt[mx] == 1) // one color has the occurence 1 more than any other color
            ok = true;
        if (ok)
            ans = i;
    }
    printf ("%d", ans);
    return 0;
}
