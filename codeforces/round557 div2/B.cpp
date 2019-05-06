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

const int maxn = 52;

int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn], d[maxn][maxn];
int n, m;

int main() {
    cin >>  n >> m;
    rep (i, 1, n) rep (j, 1, m) cin >> a[i][j];
    rep (i, 1, n) rep (j, 1, m) cin >> b[i][j];
    bool f = true;
    int x = -1;
    rep (i, 1, n) {
        rep (j, 1, m) {
            int x1 = min (a[i][j], b[i][j]);
            int x2 = max (a[i][j], b[i][j]);
            if (i == 1 && j == 1) {
                c[i][j] = x1;
                d[i][j] = x2;
            } else if (i == 1) {
                if (x1 > c[i][j - 1]) c[i][j] = x1, d[i][j] = x2;
                else if (x2 > c[i][j - 1]) c[i][j] = x2, d[i][j] = x1;
                else {
                    f = false;
                    break;
                }
            } else if (j == 1) {
                if (x1 > c[i - 1][j]) c[i][j] = x1, d[i][j] = x2;
                else if (x2 > c[i - 1][j]) c[i][j] = x2, d[i][j] = x1;
                else {
                    f = false;
                    break;
                }
            } else {
                if (x1 > c[i - 1][j] && x1 > c[i][j - 1]) c[i][j] = x1, d[i][j] = x2;
                else if (x2 > c[i - 1][j] && x2 > c[i][j - 1]) c[i][j] = x2, d[i][j] = x1;
                else {
                    f = false;
                    break;
                }
            }
        }
    }
    if (!f) cout << "Impossible" << endl;
    else {
        rep (i, 1, n) {
            rep (j, 1, m) {
                if (i == 1 && j == 1) continue;
                else if (i == 1) {
                    if (d[i][j] <= d[i][j - 1]) {
                        f = false;
                        break;
                    }
                } else if (j == 1) {
                    if (d[i][j] <= d[i - 1][j]) {
                        f = false;
                        break;
                    }
                } else {
                    if (d[i][j] <= d[i - 1][j] || d[i][j] <= d[i][j - 1]) {
                        f = false;
                        break;
                    }
                }
            }
        }
        if (f) {
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}
