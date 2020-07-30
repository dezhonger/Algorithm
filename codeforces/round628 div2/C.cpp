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

const int maxn = 200010;


int tot = 1, ver[maxn], head[maxn], nxt[maxn], edge[maxn];
int n, res[maxn], to[maxn];
void add (int x, int y, int z) {
    ver[++tot] = y;
    edge[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}


int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    int x, y;
    cin >> n;

    tot = 1;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        x--;
        y--;
        to[x]++;
        to[y]++;
        add (x, y, 0);
        add (y, x, 0);
    }
    int maTo = -1, node = -1;
    for (int i = 0; i < n; i++) {
        if (to[i] > maTo) {
            maTo = to[i];
            node = i;
        }

    }
    Debug(node)
    CLR (res, -1);
    if (maTo == 2) {
        for (int i = 0; i < n - 1; i++) res[i] = i;
    } else {
        int k = 0;
        for (int i = head[node]; i; i = nxt[i]) {
            res[i / 2  - 1] = k++;
        }
        for (int i = 0; i < n - 1; i++) if (res[i] == -1) res[i] = k++;
    }
    for (int i = 0; i < n - 1; i++) {
        printf ("%d\n", res[i]);
    }





    return 0;
}
