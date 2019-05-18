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

const int maxn = 1000;
int n, l[maxn], r[maxn];
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) s = s + s[i];
    for(int i = 0; i < n; i++) s = s + s[i];
    for(int i = n; i < n + n ; i ++) {
        l[i] = r[i] = 1;
        char c = s[i];
        char tmp = c;
        if(tmp != 'w') {
            for(int j = i - 1; j > i - n; j--) {
                if(s[j] == tmp || s[j] == 'w') l[i]++;
                else break;
            }
            for(int j = i + 1; j < i + n; j++) {
                if(s[j] == tmp || s[j] == 'w') r[i]++;
                else break;
            }
        } else {

            tmp = 'r';
            int lc = 1;
            int rc = 1;
            for(int j = i - 1; j > i - n; j--) {
                if(s[j] == tmp || s[j] == 'w') lc++;
                else break;
            }
            for(int j = i + 1; j < i + n; j++) {
                if(s[j] == tmp || s[j] == 'w') rc++;
                else break;
            }

            l[i] = max(l[i], lc);
            r[i] = max(r[i], rc);

            tmp = 'b';
            lc = 1;
            rc = 1;
            for(int j = i - 1; j > i - n; j--) {
                if(s[j] == tmp || s[j] == 'w') lc++;
                else break;
            }
            for(int j = i + 1; j < i + n; j++) {
                if(s[j] == tmp || s[j] == 'w') rc++;
                else break;
            }
             if (i == n + 1) cout << rc << endl;
            l[i] = max(l[i], lc);
            r[i] = max(r[i], rc);
        }
        l[i - n] = l[i];
        r[i - n] = r[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
//        cout << i << " " << l[i] << " " << r[i] << endl;

        int tmp = r[i] + l[(i - 1 + n) % n];
//        cout << i << " " << tmp << endl;
        if (ans < tmp) ans = tmp;
//        if (ans >= 77) cout << i << endl;

    }
    cout << min(ans, n) << endl;
    return 0;
}
