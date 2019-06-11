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

const LL INF = 1ll << 32;
LL res = 0;
int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);

    int n;
    cin >> n;
    stack<LL> sta;
    sta.push (1);
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        if (t == "for") {
            int x;
            cin >> x;
            sta.push (min (INF, sta.top() * x));
        } else if (t == "end") {
            sta.pop();
        } else {
            res += sta.top();
        }


    }

    if (res >= INF) {
        cout << "OVERFLOW!!!" << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}
