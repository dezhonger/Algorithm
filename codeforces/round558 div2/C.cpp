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

int gcd (int a, int b) {
    return b == 0 ? a : gcd (b, a % b);
}

//int gcd(int a, int b)
//{
//	if (a == 0)
//		return b;
//	return gcd(b % a, a);
//}


const int maxn = 1005;
int n, x[maxn], y[maxn];
map<pair<int, int>, set<long long>> slope_map;

int main() {
    cin >> n;
    rep (i, 1, n) cin >>  x[i] >> y[i];
    LL res = 0;
    LL total = 0;
    rep (i, 1, n - 1) rep (j, i + 1, n) {
        int x1 = x[i];
        int y1 = y[i];
        int x2 = x[j];
        int y2 = y[j];
        int a = y1 - y2;
        int b = x1 - x2;

        int d = gcd (abs(a), abs(b));
        a /= d ;
        b /= d ;
        if (a < 0 || (a == 0 && b < 0)) {
            a = -a;
            b = -b;
        }

        pair<int, int> slope (a, b);
        LL c = 1LL * a * x1 - 1LL * b * y1;
        if (!slope_map[slope].count (c)) {
            total++;
            slope_map[slope].insert (c);
            res += total - slope_map[slope].size();
        }
    }
    cout << res << endl;
    return 0;
}
