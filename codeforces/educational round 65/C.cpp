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

const int maxn = 500010;
int s[maxn];
int num[maxn];

int findSet (int x) {
    if (x == s[x]) return x;
    else return s[x] = findSet (s[x]);
}

void unionSet (int x, int y) {
    int fx = findSet (x);
    int fy = findSet (y);
    if (fx != fy) {
        num[fy] += num[fx];
        s[fx] = fy;
    }
}

int n, m;

int main() {
    cin >> n >> m;
    rep (i, 1, n) s[i] = i, num[i] = 1;
    rep (i, 1, m) {
        int x, y, z;
        cin >> x;
        if (x > 0) cin >> y;
        for (int j = 1; j < x ; j++) {
            cin >> z;
            unionSet (y, z);
        }
    }
    rep (i, 1, n) {
        cout << num[findSet (i)] << " ";
    }
    return 0;
}
