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

LL u, v;
LL b[100];

LL f (LL x, int even) {
    if (even) {
        if (x & 1) return x - 1;
        return x;
    } else {
        if (x & 1) return x;
        return x - 1;
    }
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    scanf ("%lld%lld", &u, &v);
    if (u > v) {
        printf ("-1\n");
        return 0;
    }
    if (u == 0 && v == 0) {
        printf ("0\n");
        return 0;
    }

    vector<LL> res;
    res.push_back(u);
    LL diff = v - u;

    int mam = 0;
    bool can = true;
    for (int i = 61; i >= 0; i--) {
        LL x = 1LL << i;
        if (x > diff) continue;
        LL y = diff / x;

        LL has = x & u;

        b[i] = f (y, 1);
        //cout << i << " " << x << " " << has << " " << b[i] << endl;
        if (b[i] < 0) {
            can = false;
            break;
        }
        mam = max (mam, (int) b[i]);
        diff = diff - b[i] * x;
    }
    if (!can || diff != 0) {
        printf ("-1\n");
        return 0;
    }


    for (int i = 61; i >= 0; i--) {
        LL x = 1LL << i;
        LL has =x & u;
        if (!has && b[i] > 0) {
            //is zero
            b[i]--;
            res[0] |= x;

        }
    }

    for (int i = 1; i <= mam; i++) {
        LL tmp = 0;
        for (int j = 61; j >= 0; j--) {
            if (b[j] > 0) {
                b[j]--;
                tmp |= (1LL << j);
            }
        }
        res.push_back (tmp);
    }
    //cout << mam << endl;
    int a = 0;
    for (int i = 0; i < mam + 1; i++) {
        if (res[i] == 0) continue;
        a++;
        //printf ("%lld ", res[i]);
    }
    cout << a << endl;
        for (int i = 0; i < mam + 1; i++) {
        if (res[i] == 0) continue;
        a++;
        printf ("%lld ", res[i]);
    }
    printf ("\n");

    return 0;
}
