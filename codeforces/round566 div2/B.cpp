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

int h, w;
const int maxn = 550;
string s[550];
int v[maxn][maxn];
int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);

    cin >> h >> w;
    for (int i = 0; i < h; i++) cin >> s[i];
    if (h < 3 || w < 3) {
        cout << "NO" << endl;
        return 0;
    }
    int x, y;
    x = y = -1;
    bool f = false;
    for (int i = 1; i < h - 1; i++) {
        for (int j = 1; f == false && j < w - 1; j++) {
            if (s[i][j] == '*' &&
                    s[i - 1][j] == '*' &&
                    s[i + 1][j] == '*' &&
                    s[i][j - 1] == '*' &&
                    s[i][j + 1] == '*'
               ) {
                x = i;
                y = j;
                f = true;
                break;;
            }
        }
    }
    //cout << x << " " << y << endl;
    if (!f) {
        cout << "NO" << endl;
        return 0;
    }
    v[x][y] = 1;
    for (int i = x - 1; i >= 0; i--) {
        if (s[i][y] == '*') v[i][y] = 1;
        else break;
    }
    for (int i = x + 1; i < h; i++) {
        if (s[i][y] == '*') v[i][y] = 1;
        else break;
    }
    for (int i = y - 1; i >= 0; i--) {
        if (s[x][i] == '*') v[x][i] = 1;
        else break;
    }
    for (int i = y + 1; i < w; i++) {
        if (s[x][i] == '*') v[x][i] = 1;
        else break;
    }
    bool res = true;
    for (int i = 0; i < h; i++) {
        for (int j = 0; res && j < w; j++) {
            if (v[i][j] == 0 && s[i][j] == '*') {
                res = false;
                break;
            }
        }
    }
    if (res) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
