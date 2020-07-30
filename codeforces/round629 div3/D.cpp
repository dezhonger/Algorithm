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


const int maxn = 2000020;
int a[maxn], c[maxn];

int t, n;

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);

    cin >> t;
    while (t--) {
        cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert (a[i]);
        }
        int dif = s.size();
        if (dif == 1) {
            cout << 1 << endl;
            for (int i = 0; i < n; i ++) cout << 1 << " ";
        } else {
            int hasSame = 0;
            int x;
            for (int i = 1; i < n; i++) {
                if (a[i] == a[i - 1]) {
                    hasSame = 1;
                    x = i;
                    break;
                }
            }

            c[0] = 1;
            int last = 1;
            for (int i = 1; i < n - 1; i++) {
                if (a[i] != a[i - 1]) last = 3 - last;
                c[i] = last;
            }
            if (a[n - 1] != a[n - 2]) last = 3 - last;
            if (a[n - 1] == a[0]) c[n - 1] = last;
            else {
                if (last != 1)  c[n - 1] = last;
                else c[n - 1] = 3;
            }

            int ans =  c[n - 1] == 3 ? 3 : 2;

            if (ans == 3 && hasSame == 1) {
                ans = 2;
                for (int j = x; j < n - 1; j++) c[j] = 3 - c[j];
                c[n - 1] = 2;

            }
            cout << ans << endl;
            for (int i = 0; i < n; i ++) cout << c[i] << " ";

        }
        cout << endl;

    }
    return 0;
}
