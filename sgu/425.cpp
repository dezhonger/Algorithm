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




const int MAX_BASE = 62;
int n;
long long a[110], b[110];

void cal() {
    for (int i = 0; i < n; ++i) for (int j = MAX_BASE; j >= 0; --j)
            if (a[i] >> j & 1) {
                if (b[j]) a[i] ^= b[j];
                else {
                    b[j] = a[i];
                    for (int k = j - 1; k >= 0; --k) if (b[k] && (b[j] >> k & 1)) b[j] ^= b[k];
                    for (int k = j + 1; k <= MAX_BASE; ++k) if (b[k] >> j & 1) b[k] ^= b[j];
                    break;
				}
            }
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cal();
	long long ans = 0;
	for (int i = MAX_BASE; i >= 0; i--) {
		ans ^= b[i];
	}
	cout << ans << endl;
	return 0;
}