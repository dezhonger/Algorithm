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
    string a, b;
    while (cin >> a >> b) {
        int len1 = a.length();
        int len2 = b.length();
        int len = max (len1, len2);
        string aa = a + a;
        string bb = b + b;
        int res = 0;
        int MAX = 2 * len2;
        for (int i = 0; i < MAX; i++) {
            char c1 = a[i % len1];
            char c2 = b[i % len2];
            if (c1 < c2) {
                res = -1;
                break;
            } else if (c1 > c2) {
                res = 1;
                break;
            }
        }
        cout << (res < 0 ? '<' : (res == 0 ? '=' : '>')) << endl;
    }

    return 0;
}
