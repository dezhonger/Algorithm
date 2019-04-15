#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=1005;

//f[i][j]表示在考虑完前i个挑战后，完成了j个挑战后剩余的最大值
//不参加第i+1个挑战:f[i+1][j] = f[i][j] + c[i]
//参加i+1个挑战: f[i+1][j] = max(f[i+1][j], min(f[i][j], b[i+1]) -a[i+1] + c[i+1])
//体力值必须保持>0
LL f[N][N];
int n,a[N],b[N],c[N],m;
void run()
{
    scanf("%d%d",&n,&m);

    rep(i,1,n)scanf("%d%d%d",&a[i],&b[i],&c[i]);

    rep(i,0,n)rep(j,0,n)f[i][j]=0;
    f[0][0]=m;
    rep(i,0,n-1)rep(j,0,i)if(f[i][j])
    {
        f[i+1][j]=max(f[i+1][j],f[i][j]+c[i+1]);
        if(min(f[i][j],b[i+1]*1ll)>a[i+1])
            f[i+1][j+1]=max(f[i+1][j+1],min(f[i][j],b[i+1]*1ll)-
                            a[i+1]+c[i+1]);
    }
    per(i,n,0)if(f[n][i])
    {
        printf("%d\n",i);
        return;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    assert(1<=t&&t<=50);
    while(t--) run();
    return 0;
}
