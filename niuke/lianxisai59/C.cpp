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

int t, x, y;


int g1 (int x, int y) {
    int z = (4 * y - x + 2) / 3;
    z = max (0, z);
    z = min (z, x);
    z = min (z, y);
    int z1 = z / 5 * 2;
    int z2 = y - z;
    int res1 = z1 + z2;
    x -= z1 * 5;
    x -= 4 * z2;
    y -= z1 * 5;
    y -= z2;

    if (x >= 4 && y >= 1) res1++;
    else if (x >= 2 && y >= 3) res1++;

    return res1;
}

int g2 (int x, int y) {
    int z = 3 * x - 2 * y;
    z = max (0, z);
    z = min (z, x);
    z = min (z, y);
    int z1 = z / 5 * 2;
    int z2 = (x - z) / 2;
    int res1 = z1 + z2;
    x -= z1 * 5;
    x -= 2 * z2;
    y -= z1 * 5;
    y -= 3 * z2;

    if (x >= 2 && y >= 3) res1++;
    else if (x >= 4 && y >= 1) res1++;

    return res1;
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (x == y) {
            cout << x / 5 * 2 << endl;
        } else {
            cout << g1(x, y) << endl;
            cout << g2(x, y) << endl;
            cout << max (g1 (x, y), g2 (x, y)) << endl;
        }

    }
    return 0;
}
