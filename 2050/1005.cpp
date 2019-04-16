//dp http://acm.hdu.edu.cn/showproblem.php?pid=6494
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

int test, n, f[10011][11][11];
char str[10011];

struct node {
    int x, y, z;

};



node calc (int i, int j) {
    //计算i:j这个比分后会转化为哪个比分，结果为node(x, y, z）x:y表示新的比分，z表示有没有完成新的一局
    node tmp;
    if (i == 11 || j == 11) {
        tmp.z = 1;
        tmp.x = tmp.y = 0;
    } else {
        tmp.z = 0;
        //10:10 和9:9是相同的，我们可以把分数都限制在10分之内(<=10)
        if (i == 10 && j == 10) {
            tmp.x = tmp.y = 9;
        } else {
            tmp.x = i;
            tmp.y = j;
        }
    }
    return tmp;
}


int main() {
    scanf ("%d", &test);
    while (test--) {
        scanf ("%s", str);
        n = strlen (str);
        memset (f, 128, sizeof (f) );
        //f[i][j][k]表示填完前i个局中的所有括号，当前比分是x:y的话，最多完成了几局对局
        f[0][0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 10; j++) {
                for (int k = 0; k <= 10; k++) {
                    if (f[i - 1][j][k] < (1 << 30) ) {
                        if (str[i - 1] == 'A' || str[i - 1] == '?') {
                            node tmp = calc (j + 1, k);
                            f[i][tmp.x][tmp.y] = max (f[i][tmp.x][tmp.y], f[i - 1][j][k] + tmp.z);
                        }
                        if (str[i - 1] == 'B' || str[i - 1] == '?') {
                            node tmp = calc (j, k + 1);
                            f[i][tmp.x][tmp.y] = max (f[i][tmp.x][tmp.y], f[i - 1][j][k] + tmp.z);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= 10; j++) {
            for (int k = 0; k <= 10; k++) {
                ans = max (ans, f[n][j][k]);
            }
        }
        printf ("%d\n", ans);
    }
}
