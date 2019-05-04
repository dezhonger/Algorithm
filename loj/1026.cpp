#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int p, n, m, k, dp[210][50], sum[210][210];
string s, a[10];
inline int read() { //读优。。。
    int date = 0, w = 1;
    char c = 0;
    while (c < '0' || c > '9') {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        date = date * 10 + c - '0';
        c = getchar();
    }
    return date * w;
}
bool check (int l, int r) { //判断是否有单词以s[l]为开头
    string x = s.substr (l, r - l + 1); //取出字符串
    for (int i = 1; i <= n; i++) if (x.find (a[i]) == 0) return true; //查找
    return false;
}
void init() {
    //预处理+读入
    string ch;
    s += '0'; //让下标从1开始
    p = read();
    k = read();
    for (int i = 1; i <= p; i++) {
        cin >> ch;
        s += ch;
    }
    n = read();
    m = s.length() - 1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    //预处理出sum[i][j], 表示从i到j的单词数
    for (int i = m; i >= 1; i--)
        for (int j = i; j >= 1; j--) {
            sum[j][i] = sum[j + 1][i];
            //如果以j开头有单词，那么加1
            if (check (j, i)) sum[j][i]++;
        }
}
void work() {
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) dp[i][1] = sum[1][i]; //初始化
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= k && j < i; j++)
            for (int l = j; l < i; l++)
                dp[i][j] = max (dp[i][j], dp[l][j - 1] + sum[l + 1][i]); //转移
    printf ("%d\n", dp[m][k]); //输出
}
int main() {
    init();
    work();
    return 0;
}
