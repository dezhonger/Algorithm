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

int n, x;
int cnt[10];

int cal (int x) {
    if (x == 4) return 1;
    if (x == 8) return 2;
    if (x == 15) return 3;
    if (x == 16) return 4;
    if (x == 23) return 5;
    if (x == 42) return 6;
}

int main() {
    cin >> n;
    cnt[0] = 10000000;
    rep (i, 1, n) {
        cin >> x;
        x = cal (x);
        if (cnt[x - 1] > 0) {
            cnt[x - 1]--;
            cnt[x]++;
        }

    }
    cout << n - 6 * cnt[6] << endl;

}
