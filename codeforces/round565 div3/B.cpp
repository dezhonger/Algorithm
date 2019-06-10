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

int n, t, x;
int b[3];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        int ans = 0;
        b[0] = b[1] = b[2] = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            b[x % 3]++;
        }
        ans += b[0];

        int x1 = 0;
        int x2 = 0;
        int x3 = 0;


        x1 += b[1] / 3;
        x1 += b[2] / 3;
        x1 += min(b[1] % 3, b[2] % 3);





        if (b[1] < b[2]) {
            x2 += b[1];
            b[2] -= b[1];
            x2 = x2 + b[2] / 3;
        } else {
            x3 += b[2];
            b[1] -= b[2];
            x3 = x3 + b[1] / 3;
        }
        int ma = max(x1, max(x2, x3));

        cout << ans + ma << endl;


    }
    return 0;
}
