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

int n;
const int maxn = 55;
char s[maxn][maxn];

bool check(int i, int j) {
    if (i + 2 > n) return false;
    if (j == 1) return false;
    if (j == n) return false;
    if (s[i+1][j] == '#') return false;
    if (s[i+2][j] == '#') return false;
    if (s[i+1][j+1] == '#') return false;
    if (s[i+1][j-1] == '#') return false;
    s[i+1][j] = '#';
    s[i+2][j] = '#';
    s[i+1][j+1] = '#';
    s[i+1][j-1] = '#';
    return true;
}

int main() {
    cin >> n;
    rep(i, 1, n) {
        scanf("%s", s[i] + 1);
    }

    for (int i = 1; i <= n ;i++) {
        for (int j = 1; j <= n ;j++) {
            if (s[i][j] == '#') continue;
            else {
                bool r = check(i, j);
                if (!r) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }

    }
    cout << "YES" << endl;

    return 0;
}
