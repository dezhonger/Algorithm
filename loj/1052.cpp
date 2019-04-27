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

int L, S, T, M;
int a[105], f[105];
//todo 做了一半，看错题目了，是不能踩到石子上

int main() {
    cin >> L >> S >> T >> M;
    rep(i, 1, M) cin >> a[i];
    sort(a + 1, a + 1 + M);
    CLR(f, 0x7f);
    f[0] = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = S; j <= T; j++) {
            int pos = a[i];
            f[i] = min(f[i], )
        }
    }

    return 0;
}
