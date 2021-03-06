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

int n;
vector<int> g[1010];
int from[1010];
int to[1010];

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);

    cin >> n;
    int x, y;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back (y);
        g[y].push_back (x);
        from[x]++;
        from[y]++;
        to[x]++;
        to[y]++;
    }
    set<int> s, s2;
    for (int i = 0; i < n; i++) {
        if (to[i] == 1) {
            s.insert (i);
        }
    }
    int ques = 0;
    while (1) {
        int size = s.size();
        set<int>::iterator it = s.begin();
        int a, b;
        a = b = -1;
        while (it != s.end()) {
            while (it != s.end() && a == -1) {
                a = *it;
                it++;
                if (s2.count (a)) a = -1;
            }
            while (it != s.end() && b == -1) {
                b = *it;
                it++;
                if (s2.count (b)) b = -1;
            }
            if (a != -1 && b != -1) {
                printf ("? %d %d\n", a + 1, b + 1);
                fflush (stdout);
                int p;
                scanf ("%d", &p);
                to[p-1]--;
                s2.insert (p - 1);

                ques++;

            } else if (a != -1) {
                s2.insert (a);

            }
            a = b = -1;
            if (ques >= n / 2) break;
        }

        s.clear();
        s.insert (s2.begin(), s2.end());
        s2.clear();
        if (s.size() == 1 || ques >= n / 2) break;
    }

    cout << "! ";
    if (s.size() == 1) {
        cout << *s.rbegin() + 1 << endl;
    } else {
        int res = 0;
        int mi = 1000000;
        for (int i = 0; i < n; i++) if (to[i] < mi) {
            mi = to[i];
            res = i + 1;
        }
        cout << res << endl;
}


    return 0;
}
