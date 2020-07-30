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

int t, n;
int a[101];
vector<int> even, odd;
int main() {
	ios::sync_with_stdio (false);
    cin.tie (0);

    cin >> t;
    while (t--) {
        cin >> n;
        odd.clear();
        even.clear();


        rep(i, 1, n) {
            cin >> a[i];
            if (a[i] & 1) odd.pb(i);
            else even.pb(i);
        }

        if (even.size() > 0) {
            cout << 1 << endl;
            cout << even[0] << endl;
        } else if (odd.size() > 1) {
            cout << 2 << endl;
            cout << odd[0] <<  " " << odd[1] << endl;
        } else {
            cout << -1 << endl;
        }

    }

    return 0;
}
