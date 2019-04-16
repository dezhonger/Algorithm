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
    //����i:j����ȷֺ��ת��Ϊ�ĸ��ȷ֣����Ϊnode(x, y, z��x:y��ʾ�µıȷ֣�z��ʾ��û������µ�һ��
    node tmp;
    if (i == 11 || j == 11) {
        tmp.z = 1;
        tmp.x = tmp.y = 0;
    } else {
        tmp.z = 0;
        //10:10 ��9:9����ͬ�ģ����ǿ��԰ѷ�����������10��֮��(<=10)
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
        //f[i][j][k]��ʾ����ǰi�����е��������ţ���ǰ�ȷ���x:y�Ļ����������˼��ֶԾ�
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
