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

using namespace std;

int a[6] = {4, 8, 15, 16, 23, 42};
int f (int d) {
//    cout << "d:" << d << endl;
    for (int i = 0; i < 6; i++) {
        if (a[i] * a[i] == d) return a[i];
    }
    return 0;
}

int main() {
    int r[6];
    for (int i = 0; i < 2; i++) {
        printf ("? %d %d\n", i + 1, i + 1);
        fflush (stdout);
        int x;
        scanf ("%d", &x);
        r[i] = f (x);
//        cout << r[i] << endl;
    }
    int y11, y22;
    int y1[2], y2[2];
    printf ("? 3 4\n");
    fflush (stdout);
    scanf ("%d", &y11);
    printf ("? 3 5\n");
    fflush (stdout);
    scanf ("%d", &y22);
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (a[i] * a[j] == y11) {
                y1[0] = a[i];
                y1[1] = a[j];
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (a[i] * a[j] == y22) {
                y2[0] = a[i];
                y2[1] = a[j];
            }
        }
    }
    if (y1[0] == y2[0]) {
        r[2] = y1[0];
        r[3] = y1[1];
        r[4] = y2[1];
    } else if (y1[1] == y2[1]) {
        r[2] = y1[1];
        r[3] = y1[0];
        r[4] = y2[0];
    } else  if (y1[0] == y2[1])  {
        r[2] = y1[0];
        r[3] = y1[1];
        r[4] = y2[0];
    } else {
        r[2] = y1[1];
        r[3] = y1[0];
        r[4] = y2[1];
    }
    int s = 0;
    int k = 0;
    for (int i = 0; i < 6; i++) s += a[i];
    for (int i = 0; i < 5; i++) k += r[i];
    r[5] = s - k;
    cout << "!";
    for (int i = 0; i < 6; i++) {
        cout << " " << r[i];
    }
    cout << endl;
    return 0;
}
