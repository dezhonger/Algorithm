#include<bits/stdc++.h>
#define mod 1000007
#define maxn 200001
using namespace std;
typedef long long ll;
ll n, m, k;
ll dp[maxn];
ll s[maxn];
ll g[maxn];
ll a[maxn];
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= k; i++) {
        s[i] = s[i - 1] + a[i]; //记录前缀和
    }
    for (int i = 1; i <= m; i++) {
        ll x, y;
        cin >> x >> y;
        if (x > k) continue;
        g[x] = max (g[x], y); //保留特价活动的最优减少数
    }
    for (int i = 1; i <= k; i++) { //由前推后
        for (int j = 0; j < i; j++) { //枚举最后一次的特价活动位置
            dp[i] = max (dp[i], dp[j] + s[j + g[i - j]] - s[j]);
        }
    }
    cout << s[k] - dp[k];
}
