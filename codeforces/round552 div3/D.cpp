#include <iostream>
using namespace std;

int main() {
    int n, b, a;
    cin >> n >> b >> a;
    int maxa = a;
    int x;
    int result = 0;
    for (int i = 1; i <= n ; i++) {
        cin >> x;
        if (x == 0) {
            if (a > 0) a--;
            else if (b > 0) b--;
            else break;
        } else {
            if (b > 0) {
                if (a + 1 > maxa) {
                    a--;
                } else {
                    b--;
                    a++;
                }
            } else if (a > 0) {
                a--;
            } else {
                break;
            }
        }
        result++;

    }
    cout << result << endl;
    return 0;
}
