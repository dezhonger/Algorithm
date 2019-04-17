#include <iostream>
using namespace std;


struct node {
    int a, b, c;
} nd[7];


int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int x[7] = {0, 1, 2, 0, 2, 1, 0};
    int aa = 3;
    int bb = 2;
    int cc = 2;
    int aaa = a / aa;
    int bbb = b / bb;
    int ccc = c / cc;
    int week = min (aaa, min (bbb, ccc));
    a -= week * aa;
    b -= week * bb;
    c -= week * cc;
    int maxR = 0;
    for (int i = 0; i <= 7; i++) {
        int xx[3] = {a, b, c};
        int tmp = 0;
        for (int j = i; j < i + 7; j++) {
            j %= 7;
            if (xx[x[j]] > 0) {
                xx[x[j]]--;
            } else {
                break;
            }
            tmp++;
        }
        maxR = max(maxR, tmp);
    }
    cout << maxR + week * 7 << endl;
    return 0;
}
