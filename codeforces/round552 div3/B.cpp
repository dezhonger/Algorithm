#include <bits/stdc++.h>
using namespace std;

int n;
int a[110];

bool check (int m, int x) {
    for (int i = 1 ; i <= n; i++) {
        if (a[i] == m) continue;
        if (a[i] < m) {
            if (a[i] + x != m) return false;
        } else {
            if (a[i] - x != m) return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    int mi = 2000;
    for (int i = 1; i <= n ; i++) {
        cin >> a[i];
        mi = min (mi, a[i]);
    }
    for (int i = mi; i <= 100; i++) {
        if (check ( i, i - mi)) {
            cout << (i - mi) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
