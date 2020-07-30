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

int t, n, k;
LL x;
set<int> s;

bool check (LL x) {
    int d = 0;
    while (x > 0) {
        int m = x % k;

        if (m > 1) return 0;
        if (m == 1) {
            if (s.count (d)) return 0;
            s.insert (d);
        }
        d++;
        x /= k;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        s.clear();
        bool res = true;
        rep (i, 1, n) {
            cin >> x;
            res &= check (x);
            //cout << x << " " << res << endl;
        }
        cout << (res ? "YES" : "NO") << endl;
    }
    return 0;
}
