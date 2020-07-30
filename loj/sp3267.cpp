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

#define maxn 1000010
#define maxq 200010

int a[maxn], cnt[maxn], belong[maxn];
int n, m, sz, bnum, ans[maxn], now;
struct query {
    int l, r, id;
} q[maxq];

int cmp (query x, query y) {
    return belong[x.l] == belong[y.l] ? x.r < y.r : belong[x.l] < belong[y.l];
}

void add (int pos) {
    if (cnt[a[pos]] == 0) now++;
    cnt[a[pos]]++;
}

void del (int pos) {
    cnt[a[pos]]--;
    if (cnt[a[pos]] == 0) now--;
}

int main() {
    scanf ("%d", &n);
    //每个块的代销
    sz = sqrt (n);
    //一共多少个块
    bnum = ceil ( (double) n / sz);
    //初始化每个位置对应的块是多少
    for (int i = 1; i <= bnum; i++) {
        for (int j = (i - 1) * sz + 1; j <= i * sz; j++) {
            belong[j] = i;
        }
    }
    //读入数组
    for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
    //m个询问
    scanf ("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort (q + 1, q + m + 1, cmp);

    //初始化
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++) {
        int ql = q[i].l;
        int qr = q[i].r;
        while (l < ql) del (l++);
        while (l > ql) add (--l);
        while (r < qr) add (++r);
        while (r > qr) del (r--);
        ans[q[i].id] = now;
    }
    for (int i= 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
