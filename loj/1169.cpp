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

const int maxn = 2010;
int n, m;
int l[maxn][maxn], u[maxn][maxn], x[maxn][maxn], a[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
    rep(i, 1, n) {
        rep(j, 1, m) {
            if(i == 1 || j == 1) l[i][j] = u[i][j] = x[i][j] = 1;
            else {
                //ÉÏ±ß
                int up = u[i][j];
                if(a[i - 1][j] + a[i][j] == 1) up = max(up, 1 + up[i - 1][j]);

                //×ó±ß
                int left = l[i][j];
                if(a[i][j - 1] + a[i][j] == 1) left = max(left, 1 + l[i][j - 1]);

                //×óÉÏ½Ç
                int x = 1;
                if(a[i - 1][j - 1]  + a[i][j] == 1) {
                    x = max(x, 1 + x[i-1][j-1]);
                }

            }
        }
    }
    return 0;
}
