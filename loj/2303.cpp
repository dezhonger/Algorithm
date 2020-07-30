#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL phi(LL n) {
	LL res = n;
	for (LL i = 2; i * i <= n; i++) {
		if (n % i == 0) res = res / i * (i - 1);
		while (n % i == 0) n /= i;
	}
	if (n > 1) res = res / n * (n - 1);
	return res;
}

LL cal(LL n) {
	LL res = 0, i = 1;
	for (i = 1; i * i < n; i++) {
		if (n % i == 0) {
			res += i * phi(n / i);
			res += n / i * phi(i);
		}
	}
	if (i * i == n) res += i * phi(i);
	return res;
}

int main() {
	LL x;
	cin >> x;
	cout << cal(x) << endl;
	return 0;
}