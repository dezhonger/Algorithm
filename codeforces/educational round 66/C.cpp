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

const int N = 200010;
int a[N];
int n, k;

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    int T;
    cin >> T;
    while (T--){
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int res = -1;
        int mi = 0x7f7f7f7f;
        for (int i = 1; i <= n; i++) {
            int j = i + k;
            if (j > n) continue;
            int mid = (a[i] + a[j]) / 2;
            int dis = max(a[j] - mid, mid - a[i]);
            if (dis < mi) {
                mi = dis;
                res = mid;
            }
        }
        cout << res << endl;


    }
    return 0;
}
