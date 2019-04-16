#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long
#define mod 1000000007
using namespace std;

int read() {
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    return x;
}

struct data {
    int a, b;
} a[2005];

int n, m;
int f[2005];

bool operator< (data a, data b) {
    return a.a + a.b < b.a + b.b;
}
int main() {
    n = read();
    for (int i = 1; i <= n; i++)
        a[i].a = read(), a[i].b = read();
    memset (f, -1, sizeof (f));
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        f[0] += a[i].a;
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n ; i++) {
        cerr << a[i].a << " " << a[i].b << endl;
    }
    m = read();
    int h = 0;
    cerr << "f[0]: " << f[0] << endl;
    for (int i = 1; i <= n; i++) {
        cerr << "i:" << i << endl;
        for (int j = h; j >= 0; j--) {
            if (f[j] + a[i].b >= m)
                f[j + 1] = max (f[j + 1], f[j] - a[i].a);
            if (f[h + 1] >= 0) h++;
            cerr << "f[" << j+1 << "]:" << f[j+1] << endl;
        }
    }
    //have sort
    for (int i = 1; i <= n ; i++) {
    }
    printf ("%d", h);
    return 0;
}
