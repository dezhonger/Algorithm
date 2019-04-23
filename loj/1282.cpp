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
//f[i][j]表示前i个数字中第一行的数字为j的交换次数
int a[1001], b[1001], f[1001][6001];
int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n ; i++) {
        cin >> a[i] >> b[i];
        sum = sum + a[i] + b[i];
    }
    memset (f, 0x7F, sizeof (f));
    f[1][a[1]] = 0;
    f[1][b[1]] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 6 * n; j >= 0; j--) {
            if (j  - a[i] >= 0) f[i][j] = min (f[i][j], f[i - 1][j - a[i]]);
            if (j  - b[i] >= 0) f[i][j] = min (f[i][j], f[i - 1][j - b[i]] + 1);
        }
    }
    int mi = 10000000;
    int result = 2000;
//    for (int j = 0; j <= 6 * n; j++) {
//        cout << "j: " << j << endl;
//        cout << f[n][j] << endl;
//    }
    for (int j = 0; j <= 6 * n; j++) {
        if (f[n][j] <= n) {
            int cur = abs (sum - j - j);
            if (cur < mi) {
                mi = cur;
                result = f[n][j];
            } else if (cur == mi) {
                result = min (result, f[n][j]);
            }
        }
    }
    cout << result << endl;
    return 0;
}
