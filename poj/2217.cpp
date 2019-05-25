#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define reps(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back
#define ps push
#define mp make_pair
#define CLR(x,t) memset(x,t,sizeof x)
#define LEN(X) strlen(X)
#define F first
#define Debug(x) cout<<#x<<"="<<x<<endl;


const double euler_r = 0.57721566490153286060651209;
const double pi = 3.141592653589793238462643383279;
const double E = 2.7182818284590452353602874713526;
const int inf = ~0U >> 1;
const int MOD = int (1e9) + 7;
const double EPS = 1e-6;

typedef long long LL;

const int MAX_N = 100010;
int n, k;
int rak[MAX_N + 1];//rank
int tmp[MAX_N + 1];
int sa[MAX_N + 1];
int lcp[MAX_N + 1];

//比较 (rank[i], rank[i+k]) 和 (rank[j], rank[j+k])
bool compare_sa(int i, int j) {
    if(rak[i] != rak[j]) return rak[i] < rak[j];
    else {
        int ri = i + k <= n ? rak[i + k]  : -1;
        int rj = j + k <= n ? rak[j + k]  : -1;
        return ri < rj;
    }
}

//计算字符串S的后缀数组
void construct_sa(string S) {
    n = S.length();
    //初始长度为1, rank直接取字符的编码
    for(int i = 0; i <= n; i++) {
        sa[i] = i;
        rak[i] = i < n ? S[i] : -1;
    }

    //利用对长度为k的排序结果对长度为2k的排序
    for(k = 1; k <= n; k <<= 1) {
        sort(sa, sa + n + 1, compare_sa);
        //先在tmp中临时存储新计算的rank，再转存回rank中
        tmp[sa[0]] = 0;
        for(int i = 1; i <= n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (compare_sa(sa[i - 1], sa[i]) ? 1 : 0);
        }
        for(int i = 0; i <= n; i++) {
            rak[i] = tmp[i];
        }
    }
}

void construct_lcp(string S) {
    n = S.length();
    for(int i = 0; i < n ; i++) rak[sa[i]] = i;
    int h = 0;
    //lcp[i] = S[sa[i]]和S[sa[i+1]]的最长公共前缀
    lcp[0] = 0;
    for(int i = 0; i < n; i++) {
        //计算字符串中从位置i开始的后缀及其在后缀数组中的前一个后缀的lco
        int j = sa[rak[i] - 1];
        //将h先减去首字母的1长度，在保持前缀相同的前提下不断增加
        if(h > 0) h--;
        for(; j + h < n && i + h < n; h++) {
            if(S[j + h] != S[i + h]) break;
        }
        lcp[rak[i] - 1] = h;
    }
}

int cnt;
string S, T;
int main() {
    scanf("%d\n", &cnt);
    while(cnt--) {
        getline(cin, S);
        getline(cin, T);
        string st = S + '\0' + T;
        construct_sa(st);
        construct_lcp(st);
        int ans = 0;
        int s1 = S.length();
        for(int i = 0; i < st.length(); i++) {
            if((sa[i] < s1) != (sa[i + 1] < s1)) {
                ans = max(ans, lcp[i]);
            }
        }
        printf("Nejdelsi spolecny retezec ma delku ");
        printf("%d", ans);
        printf(".\n");
    }
    return 0;
}
