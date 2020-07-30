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
#define Debug(x) cout<<#x<<"="<<x<<endl;


const double euler_r = 0.57721566490153286060651209;
const double pi = 3.141592653589793238462643383279;
const double E = 2.7182818284590452353602874713526;
const int inf = ~0U >> 1;
const int MOD = int (1e9) + 7;
const double EPS = 1e-6;

typedef long long LL;
int n;
int dp[10005][10005];
int cal (string s, int l, int r) {
    if (dp[l][r] >= 0) return dp[l][r];
    if (l == r) return 1;
    if (l > r) return 0;
    dp[l][r] = 10000000;
    if (s[l] == '(' && s[r] == ')') {
        dp[l][r] = min (cal (s, l + 1, r - 1), dp[l][r]);
    }
    for (int i = l; i < r; i++) {
        dp[l][r] = min (dp[l][r], cal (s, l, i) + cal (s, i + 1, r));
    }
    return dp[l][r];
}


int main() {
    int T;
    cin >> T;


    for (int k = 0; k < T; k++) {
        cin >> n;

        string s;
        cin >> s;
        cout << s << endl;

        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dp[i][j] = -1;
        cout << cal (s,  0, n - 1);

    }
    return 0;
}










