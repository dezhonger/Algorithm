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



int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    string s;
    cin >> s;
    int len = s.length();
    int cnt = 0;
    int l = 0, r = len - 1;
    vector<int> a;
    vector<int> b;
    while (l < r) {
        while (l < r && s[l] != '(') l++;
        while (l < r && s[r] != ')') r--;

        if (l < r) {
            a.push_back (l);
            b.push_back (r);
            l++;
            r--;
            cnt = 1;
        }
    }
    cout << cnt << endl;
    if (cnt == 1) {
        int as = a.size();
        int bs = b.size();
        cout << as + bs << endl;
        for (int i = 0; i < as; i++) cout << a[i] + 1 << " ";
        for (int i = as - 1; i  >= 0; i--) cout << b[i] + 1 << " ";
        cout << endl;
    }

    return 0;
}
