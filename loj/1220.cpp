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


int n, c;
int pos[51], g[51], gsum[51];
int f[51][51][2];

//计算[a,b]区间外的路灯功率之和
int gg (int a, int b) {
    int tmp = gsum[b] - gsum[a - 1];
    return gsum[n] - tmp;
}

int main() {
    cin >> n >> c;
    rep (i, 1, n) cin >> pos[i] >> g[i];
    rep (i, 1, n) gsum[i] = gsum[i - 1] + g[i];
    CLR (f, 0x7f);
    f[c][c][0] = f[c][c][1] = 0;
    for (int len = 2; len <= n ; len++) {
        for (int i = 1; i <= n; i++) {
            int j = i + len - 1;
            if (j > n) continue;
            f[i][j][0] = min (f[i + 1][j][0] + gg (i + 1, j) * (pos[i + 1] - pos[i]), f[i + 1][j][1] + gg (i + 1, j) * (pos[j] - pos[i]));
            f[i][j][1] = min (f[i][j - 1][1] + gg (i, j - 1) * (pos[j] - pos[j - 1]), f[i][j - 1][0] + gg (i, j - 1) * (pos[j] - pos[i]));
        }
    }
    cout << min (f[1][n][0], f[1][n][1]) << endl;
    return 0;
}
