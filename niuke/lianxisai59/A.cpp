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


bool check(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    if (len2 > len1) return false;
    int j = 0;
    for (int i = 0; i < len1; i++) {
        if (s1[i] == s2[j]) {
            j++;
        }
        if (j == len2) {
            break;
        }

    }
    return j == len2;

}


int main() {
	ios::sync_with_stdio (false);
    cin.tie (0);

    string s;
    cin >> s;
    cout << check(s, "XiaoQiao") << endl;
    cout << check(s, "XiaoHuiHui") << endl;
    bool f = check(s, "XiaoQiao") && check(s, "XiaoHuiHui");
    cout << (f ? "Happy" : "emm") << endl;
    return 0;
}
