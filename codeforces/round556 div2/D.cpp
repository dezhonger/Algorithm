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

int n, q;
const int maxn = 100010;
char s[maxn];
int v[maxn];
char a, c;
int b;
int cnt[26];
vector<int> ve[4];
int main() {
    cin >> n >> q;
    scanf ("%s", s);
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        cnt[x]++;
    }
    for (int i = 1; i <= q; i++) {
        cin >> a;
        if (a == '+') {
            cin >> b >> c;
            int st = -1;
            if (!ve[b].empty()) {
                st = ve[b].back();
            }
            int f = 0;
//            cout << "st: " << st << endl;
            for (int j = st + 1; j < n; j++) {
                if (v[j] == 0 && s[j] == c) {
                    ve[b].push_back (j);
                    v[j] = b;
                    cnt[c - 'a']--;
                    cout  << "YES" << endl;
                    f = 1;
                    break;
                }
            }
            if (!f) cout << "NO" << endl;
        } else {
            cin >> b;
            if (ve[b].empty()) cout << "NO" << endl;
            else {
                int k = ve[b].back();
                v[k] = 0;
                cnt[s[k] - 'a']++;
                ve[b].pop_back();
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}
