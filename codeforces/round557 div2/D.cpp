#include <cstdio>
#include <unordered_set>
#include <vector>
using namespace std;


#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define reps(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back

typedef long long ll;
int n, m;
ll chord(ll x, ll y) {
    //merge to a number
    x %= n;
    y %= n;
    if (x > y) swap(x, y);
    return (x << 32) | y;
}

ll rorate(ll c, int a) {

    ll x = c >> 32;
    ll y = c & ((1LL << 32) - 1);
    return chord(x + a, y + a);
}




int main() {
    unordered_set<ll> us;
    vector<ll> cs;
    scanf ("%d%d", &n, &m);
    reps (i, 0, m) {
        int x, y;
        scanf ("%d%d", &x, &y);
        ll c = chord (x, y);
        cs.pb (c);
        us.insert (c);
    }
    //divisor
    reps (i, 1, n) {
        if (n % i) continue;
        bool ok = true;
        for (auto &x : cs) {
            if (us.count (rorate (x, i))) {
                ok = false;
                break;
            }
        }
        if (ok) {
            printf ("Yes\n");
            return 0;
        }
    }
    printf ("No\n");
    return 0;
}
