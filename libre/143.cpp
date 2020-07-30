#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t[] = { 3, 5, 7, 11, 13, 37, 79, 97 };
ll ksc(ll a, ll b, ll p) {
    ll tmp = a * b - (ll)((long double)a / p * b + 0.5) * p;
    return tmp < 0 ? tmp + p : tmp;
}
ll ksm(ll a, ll b, ll p) {
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = ksc(ans, a, p);
        b >>= 1, a = ksc(a, a, p);
    }
    return ans;
}
bool solve(ll n) {
    if (n == 2)
        return 1;
    if (n % 2 == 0 || n == 1)
        return 0;
    ll u = n - 1, tot = 0;
    while (!(u & 1)) u >>= 1, ++tot;
    for (int i = 0; i < 8; ++i) {
        if (t[i] == n)
            return 1;
        ll x = ksm(t[i], u, n), y = x;
        for (int j = 1; j <= tot; ++j) {
            x = ksc(x, x, n);
            if (x == 1 && !(y == 1 || y == n - 1))
                return 0;
            y = x;
        }
        if (x != 1)
            return 0;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n;
    while (cin >> n) cout << (solve(n) ? "Y" : "N") << '\n';
    return 0;
}