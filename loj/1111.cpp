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

struct edge {
    int x;
    int y;
    int t;

}e[100010];
int n, m, f[1010];
int cmp(const edge &a, const edge &b) {
    return a.t < b.t;
}

int findfather(int x) {
    return f[x] == x ? x : f[x] = findfather(f[x]);
}

void un(int x, int y) {
    f[x] = y;
}


int main() {
    cin >> n >> m;
    reps(i, 0, m) cin >> e[i].x >> e[i].y >> e[i].t;
    sort(e, e + m, cmp);
    rep(i, 1, n) f[i] = i;
    reps(i, 0, m) {
        int fx = findfather(e[i].x);
        int fy = findfather(e[i].y);
        if (fx != fy) un(fx, fy), n--;
        if (n == 1) {
            cout << e[i].t << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
