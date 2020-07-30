#include <bits/stdc++.h>
using namespace std;


#define Debug(x) cout<<#x<<"="<<x<<endl;
typedef long long LL;

const int N = 100100;
int n, mu[N+50], p[N+50];
int tot;
bool used[N+50];

//预处理出素数 莫比乌斯函数
void init() {
	mu[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (!used[i]) {
			mu[i] = -1;
			p[++tot] = i;
		}
		for (int j = 1; j <= tot && p[j] * i <= N; j++) {
			used[p[j] * i] = true;
			if (i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			}
			mu[i * p[j]] = mu[i] * (-1);
		}
	}
	
}


LL check(LL n) {
	LL res = 0;
	for (int i = 1; i * i <= n; i++) {
		res += mu[i] * n / (i * i);
	}
	return res;
}


LL cal(LL k) {
	LL l = 1, r = k * 2;
	LL ans;
	while (l <= r) {
		int mid = (l + r) / 2;
		int number = check(mid);
		if (number >= k) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	return ans;
}


int main() {
	int T;
	cin >> T;
	init();
	while (T--) {
		int x;
		cin >> x;
		cout << cal(x) << endl;
	}
	return 0;
}