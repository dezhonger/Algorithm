#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 200020;
int n, phi[N], p[N];
LL sum[N];
int tot;
bool used[N];

//预处理出素数 欧拉函数 欧拉函数前缀和
void init(LL n) {
	phi[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (!used[i]) {
			phi[i] = i - 1;
			p[++tot] = i;
		}
		for (int j = 1; p[j] * i <= n; j++) {
			used[p[j] * i] = true;
			if (i % p[j] == 0) {
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
			phi[i * p[j]] = phi[i] * (p[j] - 1);
		}
	}
	for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + phi[i];
}

LL cal(LL x) {
	LL res = 0;
	for (int i = 1; i <= tot; i++) {
		int t = x /p[i];
		res += 2L * sum[t] + 1;
	}
	return res;

}


int main() {
	int x;
	cin >> x;
	init(x);
	cout << cal(x) << endl;
	return 0;
}