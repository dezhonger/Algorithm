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
int mod = 998244353;
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int MAXN = 100010;
LL f[MAXN];

void init(int limit) {
    f[1] = 6;
    for (int i = 2; i <= limit; i++) {
        LL res = f[i-1] * (2 * i);
        res %= mod;
        res *= (2 * i + 1);
        res %= mod;
        LL k = (1L * i * i) % mod;
        LL tmp = powmod(k, mod - 2);
        LL o = (res * tmp) % mod;
        f[i] = o;
        //cout << i << " " << o << endl;
    }
}
int main() {


    //init(10);
    init(100000);
    int n;
    while (cin >> n) {
        cout << powmod(f[n], mod - 2) << endl;
    }
    return 0;
}
