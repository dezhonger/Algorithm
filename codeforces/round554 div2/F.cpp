#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

void add(int &a, long long b) {
    a = (a + b) % MOD;
}

int main() {
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(1<<m, 0)));
    dp[0][0][0] = 1;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= k; ++j) {
            for(int mask = 0; mask < (1<<m); ++mask) {
                int newMask = (mask << 1) % (1<<m);

                // Not visit planet i+1
                add(dp[i+1][j][newMask], dp[i][j][mask]);

                // Visit planet i+1
                if (j < k) {
                    int insertWays = __builtin_popcount(mask) + 1;
                    add(dp[i+1][j+1][newMask|1], 1LL*insertWays*dp[i][j][mask]);
                }
            }
        }
    }

    int ans = 0;
    for(int mask = 0; mask < (1<<m); ++mask)
        add(ans, dp[n][k][mask]);

    printf("%d", ans);
}