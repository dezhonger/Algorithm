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



int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return x * f;
}
#define N 55
typedef pair<int, int> pii;
int n, ans;
struct data {
    int x, y;
} a[N];
map<pii, int> f;

void print() {
    map<pii, int>::iterator it = f.begin();
    while(it != f.end()) {
        cout << (it -> F).F << " " << (it -> F).S << " " << it -> S << endl;
        it++;
    }

}

signed main() {
    n = read();
    for (int i = 1; i <= n; i++) a[i].x = read(), a[i].y = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) {
                ans = max (ans, ++f[make_pair (a[i].x - a[j].x, a[i].y - a[j].y)]);
            }

    print();
    cout << n - ans << endl;
    return 0;
    //NOTICE LONG LONG!!!!!
}
