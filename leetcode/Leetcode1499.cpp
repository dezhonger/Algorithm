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
const int mod = int (1e9) + 7;
const double EPS = 1e-6;

typedef long long LL;
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL gcd(LL a,LL b) { return b?gcd(b,a%b):a;}


class Solution {
public:
	//const int M = 100005;
	int F_Max[100005][20];
	void init(int num[], int n)
	{
		for(int i = 1; i <= n; i++)
		{
			F_Max[i][0] = num[i];
		}
	 
		for(int i = 1; (1<<i) <= n; i++)  //按区间长度递增顺序递推
		{
			for(int j = 1; j+(1<<i)-1 <= n; j++)  //区间起点
			{
				F_Max[j][i] = max(F_Max[j][i-1],F_Max[j+(1<<(i-1))][i-1]);
				//F_Min[j][i] = min(F_Min[j][i-1],F_Min[j+(1<<(i-1))][i-1]);
			}
		}
	}

    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
		int sz = points.size();
		int a[sz];
		for (int i = 0; i < sz; i++) a[i] = points[i][0];
        init(a, sz);
		int ans = INT_MIN;
		for (int i = 0; i < sz; i++) {
			
		}
    }
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}
