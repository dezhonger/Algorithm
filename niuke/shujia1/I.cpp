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

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    int n, a, b, c;
    cin >>n >> a >> b >> c;
    string s;
    cin >> s;
    int len = s.length();
    LL dp[len + 1];
    string s1 = "nico";
    string s2 = "niconi";
    string s3 = "niconiconi";
    dp[0] = 0;
    for (int i = 1; i <= len ;i++) {
        if (i >= 1) dp[i] = dp[i-1];
        if (i >= 4 && s.substr(i - 4, 4) == s1) dp[i] = max(dp[i], dp[i - 4] + a);
        if (i >= 6 && s.substr(i - 6, 6) == s2) dp[i] = max(dp[i], dp[i - 6] + b);
        if (i >= 10 && s.substr(i - 10, 10) == s3) dp[i] = max(dp[i], dp[i - 10] + c);
        //cout << i << " " << dp[i] << endl;
    }

    cout << dp[len] << endl;
    return 0;
}
