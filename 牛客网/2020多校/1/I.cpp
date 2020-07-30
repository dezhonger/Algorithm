#include<bits/stdc++.h>
#define R register
#define ll long long
#define III __int128
#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
using namespace std;
const int N=(1<<17)+5;const double Pi=acos(-1.0);
int P;III zero;
inline int add(R int x,R int y){return 1ll*x+y>=P?1ll*x+y-P:x+y;}
inline int dec(R int x,R int y){return 1ll*x-y<0?1ll*x-y+P:x-y;}
inline int mul(R int x,R int y){return 1ll*x*y-1ll*x*y/P*P;}
int ksm(R int x,R int y){
    R int res=1;
    for(;y;y>>=1,x=mul(x,x))(y&1)?res=mul(res,x):0;
    return res;
}
struct cp{
    double x,y;
    cp(){}
    cp(R double xx,R double yy):x(xx),y(yy){}
    inline cp operator +(const cp &b)const{return cp(x+b.x,y+b.y);}
    inline cp operator -(const cp &b)const{return cp(x-b.x,y-b.y);}
    inline cp operator *(const cp &b)const{return cp(x*b.x-y*b.y,x*b.y+y*b.x);}
    inline cp operator *(const double &b)const{return cp(x*b,y*b);}
    inline cp operator ~()const{return cp(x,-y);}
}w[2][N];
int r[21][N],lg[N];double inv[21];
void Pre(){
    fp(d,0,17){
        fp(i,1,(1<<d)-1)r[d][i]=(r[d][i>>1]>>1)|((i&1)<<(d-1));
        lg[1<<d]=d,inv[d]=1.0/(1<<d);
    }
    for(R int i=1,d=0;i<131072;i<<=1,++d)fp(k,0,i-1){
        w[1][i+k]=cp(cos(Pi*k*inv[d]),sin(Pi*k*inv[d])),
        w[0][i+k]=cp(cos(Pi*k*inv[d]),-sin(Pi*k*inv[d]));
    }
}
int lim,d;
void FFT(cp *A,int ty){
    fp(i,0,lim-1)if(i<r[d][i])swap(A[i],A[r[d][i]]);
    cp t;
    for(R int mid=1;mid<lim;mid<<=1)
        for(R int j=0;j<lim;j+=(mid<<1))
            fp(k,0,mid-1)
                A[j+k+mid]=A[j+k]-(t=A[j+k+mid]*w[ty][mid+k]),
                A[j+k]=A[j+k]+t;
    if(!ty)fp(i,0,lim-1)A[i]=A[i]*inv[d];
}
void MTT(int *a,int *b,int len,int *c){
    static cp f[N],g[N],p[N],q[N];
    lim=(len<<1),d=lg[lim];
    fp(i,0,len-1)f[i]=cp(a[i]>>15,a[i]&32767),g[i]=cp(b[i]>>15,b[i]&32767);
    fp(i,len,lim-1)f[i]=g[i]=cp(0,0);
    FFT(f,1),FFT(g,1);
    fp(i,0,lim-1){
        cp t,f0,f1,g0,g1;
        t=~f[i?lim-i:0],f0=(f[i]-t)*cp(0,-0.5),f1=(f[i]+t)*0.5;
        t=~g[i?lim-i:0],g0=(g[i]-t)*cp(0,-0.5),g1=(g[i]+t)*0.5;
        p[i]=f1*g1,q[i]=f1*g0+f0*g1+f0*g0*cp(0,1);
    }
    FFT(p,0),FFT(q,0);
    fp(i,0,lim-1)c[i]=(((ll)(p[i].x+0.5)%P<<30)+((ll)(q[i].x+0.5)<<15)+((ll)(q[i].y+0.5)))%P;
}
void Inv(int *a,int *b,int len){
    if(len==1)return b[0]=ksm(a[0],P-2),void();
    Inv(a,b,len>>1);
    static int c[N],d[N];
    MTT(a,b,len,c),MTT(c,b,len,d);
    fp(i,0,len-1)b[i]=dec(add(b[i],b[i]),d[i]);
}
struct node{
    node *lc,*rc;vector<int>vec;int deg;
    void Mod(const int *a,int *r,int n){
        static int A[N],B[N],D[N];
        int len=1;while(len<=n-deg)len<<=1;
        fp(i,0,n)A[i]=a[n-i];fp(i,0,deg)B[i]=vec[deg-i];
        fp(i,n-deg+1,len-1)B[i]=0;
        Inv(B,D,len);
        fp(i,n-deg+1,len-1)A[i]=D[i]=0;
        MTT(A,D,len,A);
        reverse(A,A+n-deg+1);
        len=1;while(len<=max(n-deg,deg))len<<=1;
        fp(i,0,deg)B[i]=vec[i];fp(i,deg+1,len-1)B[i]=0;
        fp(i,n-deg+1,len-1)A[i]=0;
        MTT(A,B,len,A);
        fp(i,0,deg-1)r[i]=dec(a[i],A[i]);
    }
    void Mul(){
        static int A[N],B[N];deg=lc->deg+rc->deg,vec.resize(deg+1);
        int len=1;while(len<=max(lc->deg,rc->deg))len<<=1;
        fp(i,0,lc->deg)A[i]=lc->vec[i];fp(i,lc->deg+1,len-1)A[i]=0;
        fp(i,0,rc->deg)B[i]=rc->vec[i];fp(i,rc->deg+1,len-1)B[i]=0;
        MTT(A,B,len,A);
        fp(i,0,deg)vec[i]=A[i];
    }
}pool[N<<1],*rt,*qwq,*pp=pool;
int A[N],a[N];
void solve(node* &p,int l,int r){
    p=pp++;
    if(l==r)return p->deg=1,p->vec.resize(2),p->vec[0]=a[l],p->vec[1]=1,void();
    int mid=(l+r)>>1;
    solve(p->lc,l,mid),solve(p->rc,mid+1,r);
    p->Mul();
}
int b[25],res;
void calc(node *p,int l,int r,const int *A){
    if(r-l<=512){
        fp(i,l,r){
            int x=a[i],c1,c2,c3,c4,now=A[r-l];
            b[0]=1;fp(j,1,16)b[j]=mul(b[j-1],x);
            for(R int j=r-l-1;j-15>=0;j-=16){
                c1=(zero+1ll*now*b[16]+1ll*A[j]*b[15]+1ll*A[j-1]*b[14]+1ll*A[j-2]*b[13])%P,
                c2=(zero+1ll*A[j-3]*b[12]+1ll*A[j-4]*b[11]+1ll*A[j-5]*b[10]+1ll*A[j-6]*b[9])%P,
                c3=(zero+1ll*A[j-7]*b[8]+1ll*A[j-8]*b[7]+1ll*A[j-9]*b[6]+1ll*A[j-10]*b[5])%P,
                c4=(zero+1ll*A[j-11]*b[4]+1ll*A[j-12]*b[3]+1ll*A[j-13]*b[2]+1ll*A[j-14]*b[1])%P,
                now=(0ll+c1+c2+c3+c4+A[j-15])%P;
            }
            fd(j,(r-l)%16-1,0)now=(1ll*now*x+A[j])%P;
            res=mul(res,now);
        }
        return;
    }
    int mid=(l+r)>>1,b[p->deg+1];
    p->lc->Mod(A,b,p->deg-1),calc(p->lc,l,mid,b);
    p->rc->Mod(A,b,p->deg-1),calc(p->rc,mid+1,r,b);
}
int n,s;
int main(){
    scanf("%d%d",&n,&P),res=1,s=sqrt(n),Pre(),zero=0;
    fp(i,1,s)a[i]=i-1;solve(qwq,1,s);
    fp(i,1,s)a[i]=P-((i-1)*s+1);solve(rt,1,s);
    fp(i,0,s)A[i]=qwq->vec[i];
    rt->Mod(A,A,s);
    fp(i,1,s)a[i]=(i-1)*s+1;
    calc(rt,1,s,A);
    fp(i,s*s+1,n)res=mul(res,i);
    printf("%d\n",res);
    return 0;
}
