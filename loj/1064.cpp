#include <cmath>
#include <stack>
#include <algorithm>
#include <string>
#include <deque>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <queue>
#include <cstdlib>
#include <iomanip>
using namespace std;

#define rep(i, a, b) for( i = (a); i <= (b); i++)
#define reps(i, a, b) for( i = (a); i < (b); i++)
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


int v[60 + 5][3], p[60 + 5][3];
int f[32000 + 5];


int value (int i, int x) {
    return v[i][x] * p[i][x];
}

int cost (int i, int j) {
    return v[i][j];
}

int cost (int i, int j, int k) {
    return v[i][j] + v[i][k];
}

int cost (int i, int j, int k, int x) {
    return v[i][j] + v[i][k] + v[i][x];
}




int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int _v, _p, _q;
        cin >> _v >> _p >> _q;
        if (_q == 0) {
            v[i][0] = _v;
            p[i][0] = _p;
        } else {
            if (v[_q][1] == 0) {
                v[_q][1] = _v;
                p[_q][1] = _p;
            } else {
                v[_q][2] = _v;
                p[_q][2] = _p;
            }
        }
    }
    for (int i = 1; i <= m; ++i)
        for (int j = n; j >= 0; --j) {
            if (j >= cost (i, 0)) // 够买主件
                f[j] = max (f[j], f[j - cost(i, 0)] + value (i, 0));
            if (j >= cost (i, 0, 1)) // 还够买第一个附件
                f[j] = max (f[j], f[j - cost (i, 0, 1)] + value (i, 0) + value (i, 1));
            if (j >= cost (i, 0, 2)) // 还够买第二个附件
                f[j] = max (f[j], f[j - cost (i, 0, 2)] + value (i, 0) + value (i, 2));
            if (j >= cost (i, 0, 1, 2)) // 还够买两个附件
                f[j] = max (f[j], f[j - cost (i, 0, 1, 2)] + value (i, 0) + value (i, 1) + value (i, 2));
        }
    cout << f[n] << endl;
}
