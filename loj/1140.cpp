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


int h (char c) {
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    if (c == 'T') return 3;
    return 4;
}

int g (char a, char b) {
    int x[5][5] = {
        {5, -1, -2, -1, -3},
        { -1, 5, -3, -2, -4},
        { -2, -3, 5, -2, -2},
        { -1, -2, -2, 5, -1},
        { -3, -4, -2, -1, 0},
    };
    int i = h (a);
    int j = h (b);
    return x[i][j];
}

int main() {
    int f[101][101];
    int l1, l2;
    string s1, s2;
    cin >> l1 >> s1 >> l2 >> s2;
    memset (f, 0x80, sizeof (f));
    f[0][0] = 0;

    //init important!
    for (int i = 1; i <= l1; i++) {
        f[i][0] = f[i - 1][0] + g (s1[i - 1], 'B');
    }
    for (int j = 1; j <= l2; j++) {
        f[0][j] = f[0][j - 1] + g (s2[j - 1], 'B');
    }
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            f[i][j] = max (f[i][j], f[i - 1][j - 1] + g (s1[i - 1], s2[j - 1]));
            f[i][j] = max (f[i][j], f[i - 1][j] + g (s1[i - 1], 'B'));
            f[i][j] = max (f[i][j], f[i][j - 1] + g (s2[j - 1], 'B'));
        }
    }
    cout << f[l1][l2] << endl;
    return 0;
}
