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

const int maxn = 200020;
int n, m;
int a[maxn];
vector<int> v[maxn];

//black-white ranse
void dfs (int x, int c) {
    if (a[x] > 0) {
        return ;
    }
    a[x] = c;
    for (int y : v[x]) {
        dfs (y, 3 - c);
    }

}

void solve() {
    cin >> n >> m;
    rep (i, 1, n) v[i].clear(), a[i] = 0;
    rep (i, 1, m) {
        int x, y;
        cin >> x >> y;
        v[x].push_back (y);
        v[y].push_back (x);
    }
    dfs (1, 1);
    vector<int> A, B;
    rep (i, 1, n) {
        if (a[i] == 1) A.push_back (i);
        else B.push_back (i);
    }
    if (B.size() < A.size()) A = B;
    cout << A.size() << endl;
    for (int x : A) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
