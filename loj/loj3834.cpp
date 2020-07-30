#include <cmath>
#include <stack>
#include <algorithm>
#include <string>
#include <deque>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <queue>
#include <cstdlib>
#include <iomanip>
using namespace std;

#define rep(i, a, b) for( i = (a); i <= (b); i++)
#define reps(i, a, b) for( i = (a); i < (b); i++)
#define pb push_back
#define ps push
#define mp make_pair
#define CLR(x,t) memset(x,t,sizeof x)
#define LEN(X) strlen(X)
#define F first
#define S second
#define Debug(x) cout<<#x<<"="<<x<<endl;
#define mid (l+r)/2


const double euler_r = 0.57721566490153286060651209;
const double pi = 3.141592653589793238462643383279;
const double E = 2.7182818284590452353602874713526;
const int inf = ~0U >> 1;
const int MOD = int (1e9) + 7;
const double EPS = 1e-6;

typedef long long LL;

const int M = 200010;
int n, q;
//一共有m个不同的数
int m, cnt = 0;
int a[M], b[M], T[M];
int sum[M * 40 + 5], L[M * 40 + 5], R[M * 40 + 5];

//离散化
inline int dis(int x) {
	Debug(x)
	return lower_bound(b + 1, b + m + 1, x) - b;
}


inline int build(int l, int r) {
	int root = ++cnt;
	sum[root] = 0;
	if (l < r) {
		L[root] = build(l, mid);
		R[root] = build(mid + 1, r);
	}
	return root;
}

inline int update(int pre, int l, int r, int x) {
	int root = ++cnt;
	L[root] = L[pre];
	R[root] = R[pre];
	//由于新增了一个数，对应的值是要加1的
	sum[root] = sum[pre] + 1;
	
	if (l < r) {
		if (x <= mid) L[root] = update(L[pre], l, mid, x);
		else R[root] = update(R[pre], mid + 1, r, x);
	}
	return root;
}

inline int query(int u, int v, int l, int r, int k) {
	if (l >= r) return l;
	int x = sum[L[v]] - sum[L[u]];
	if (k <= x) return query(L[u], L[v], l, mid, k);
	else return query(R[u], R[v], mid + 1, r, k - x);
}


int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	//离散化
	sort(b + 1, b + 1 + n);
	m = unique(b + 1, b + 1 + n) - b - 1;
	
	//建一个空树
	T[0] = build(1, m);
	
	for (int i = 1; i <= n; i++) {
		int val = dis(a[i]);
		
		T[i] = update(T[i-1], 1, m, val);
	}
	while (q--) {
		int x, y, z;
		cin >> x >> y >> z;
		int ans = query(T[x-1], T[y], 1, m, z);
		cout << b[ans] << endl;
	}
	
	return 0;
	
	

}