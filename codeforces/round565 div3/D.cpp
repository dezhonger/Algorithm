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

const int maxn = 3000000;
int n;
int a[maxn];
int id[maxn];
bool used[maxn];

//max divisor
int fi (int x) {
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return x / i;
}



int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    vector<int> p;
    vector<int> res;
    for (int i = 2; i < maxn; i++) {
        if (used[i]) continue;
        p.push_back (i);
        id[i] = p.size();
        for (int j = i + i; j < maxn; j += i) {
            used[j] = true;
        }
    }
    cin >> n;
    n <<= 1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = maxn - 1; i >= 2; i--) {
        while (a[i]) {
            if (!used[i]) {
                //i is prime
                res.push_back (id[i]);
                a[id[i]]--;
            } else {
                res.push_back (i);
                a[fi (i)]--;
            }
            a[i]--;
        }

    }
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
