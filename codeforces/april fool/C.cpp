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



int main() {
	ios::sync_with_stdio (false);
    cin.tie (0);
    int a[6];
    a[0] = 0;
    a[1] = 5;
    a[2] = 3;
    a[3] = 2;
    a[4] = 4;
    a[5] = 1;
    int x;
    cin >> x;
    int b[6];
    int i = 5;
    while (x){
        b[i--] = x % 2;
        x /= 2;
    }

    int c[6];
    CLR(c, 0);
    for (int i = 0; i < 6; i++ ) {
        if (b[i] == 1) {
            c[a[i]] = 1;
        }
    }
    int r = 0;
    for (int i = 0; i < 6; i++) r = r * 2 + c[i];
    cout << r << endl;

    return 0;
}