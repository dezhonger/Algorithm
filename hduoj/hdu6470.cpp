//矩阵快速幂
//http://acm.hdu.edu.cn/showproblem.php?pid=6470
//https://www.cnblogs.com/zquzjx/p/10549775.html
//https://www.cnblogs.com/shuaihui520/p/10545858.html

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL long long
#define inc(i,j,k) for(int i=j;i<=k;i++)
#define dec(i,j,k) for(int i=j;i>=k;i--)
#define gcd(i,j) __gcd(i,j)
#define mem(i,j) memset(i,j,sizeof(i))
const int N=1e5+5;
const int M=6;
const int mod=123456789;

LL n,m;
struct MAT {
    LL a[M][M];
    MAT(){ mem(a,0); }
    MAT operator*(MAT p) {
        MAT res;
        for(int i=0;i<M;i++)
        for(int j=0;j<M;j++)
        for(int k=0;k<M;k++)
            res.a[i][j]=(res.a[i][j]+a[i][k]*p.a[k][j])%mod;
        return res;
    }
};
MAT mod_pow(MAT A,LL x) {
    MAT res;
    res.a[0][0]=1;
    while(x) {
        if(x&1) res=res*A;
        A=A*A; x>>=1;
    } 
    return res;
}
void init(MAT& A,MAT& B) {
    A.a[0][0]=1,A.a[0][1]=2,A.a[0][2]=1,
    A.a[1][0]=1,
                            A.a[2][2]=1,A.a[2][3]=3,A.a[2][4]=3,A.a[2][5]=1,
                                        A.a[3][3]=1,A.a[3][4]=2,A.a[3][5]=1,
                                                    A.a[4][4]=1,A.a[4][5]=1,
                                                                A.a[5][5]=1;
    B.a[0][0]=2,B.a[1][0]=1,B.a[2][0]=27,B.a[3][0]=9,B.a[4][0]=3,B.a[5][0]=1;
}

int main()
{
    int _; scanf("%d",&_);
    while(_--) {
        LL n; scanf("%lld",&n); 
        MAT A; MAT ans;
        init(A,ans);
        ans=mod_pow(A,n-2LL)*ans;
        printf("%lld\n",ans.a[0][0]);
    }

    return 0;
}