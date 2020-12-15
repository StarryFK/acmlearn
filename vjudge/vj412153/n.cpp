#include<bits/stdc++.h>
#define Rg register
#define go(i,a,b) for(Rg int i=a;i<=b;i++)
#define yes(i,a,b) for(Rg int i=a;i>=b;i--)
#define il inline
#define ll long long
#define ld long double
#define ull unsigned long long
using namespace std;
il ll read()
{
    ll x=0,y=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')y=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x*y;
}
int T;
ll n,ans;
//-----------快速乘 快速幂 gcd f函数(生成下一个随机数的函数)
il ll mul(ll x,ll y,ll z)//一个超级快的快速乘
{
    ll sm=(ld)x/z*y;
    return ((ull)x*y-(ull)sm*z+z)%z;
}
il ll ksm(ll x,ll y,ll z)
{
  ll ans=1;
  while(y)
  {if(y&1)ans=mul(ans,x,z);x=mul(x,x,z);y>>=1;}
  return ans;
}
il ll f(ll x,ll g,ll y){return (mul(x,x,y)+g)%y;}
il ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
//-----------Miller-rabin判质数
il bool rabin(ll x,ll y)
{
    if(ksm(x,y-1,y)!=1)return 0;//费马小定理
    ll z=y-1,sm;
    while(!(z&1))
    {
        z>>=1;sm=ksm(x,z,y);
        if(sm!=1&&sm!=y-1)return 0;//二次探测
        if(sm==y-1)return 1;
    }return 1;
}
il bool miller(ll x)
{
    if(x==2||x==3||x==7||x==61||x==24251)return 1;
    if(x==46856248255981)return 0;
    return rabin(2,x)&&rabin(3,x)&&rabin(7,x)&&rabin(61,x)&&rabin(24251,x);
}
//-------------Pollard-Rho算法的主体
/*这里所写的Pollard-Rho算法不是最朴素的版本
  是一个更快更好的版本
  1.不是每次算出下一个随机数之后都算gcd,而是把算的这些数都乘起来(当然要%一下x)
  累计了一定量的数之后再求一次gcd 这样就大大减少了求gcd的次数从而提高速度
  这里选定的是127个数累计起来求一次gcd 为什么是127呢 因为它是个好数字（我也不知道）
  2.上面的优化有局限性 就是很有可能环比较小 没到127个数就出现环 这样即使已经出现过含x因数的数也会跳出循环
  遇到这样的情况就会拖慢速度 甚至永远都算不出来
  这里可以用一个倍增的方法解决这个问题 分别在生成(1,2,4,8,16,32,64...)个数的时候算一次gcd
*/
il ll Pollard(ll x)
{
    ll a,b,d,g,y,i,j;
    while(1)
    {
        a=b=rand()%x;g=rand()%x;y=1;i=0;j=1;
        while(++i)
        {
            a=(mul(a,a,x)+g)%x;y=mul(y,abs(a-b),x);
            if(a==b||!y)break;
            if(i<127||i==j)
            {
                d=gcd(x,y);if(d>1&&d!=x)return d;
                if(i==j)b=a,j<<=1;
            }
        }
    }
}
//------------递归找最小质因子
il void find(ll x)
{
    if(x<=ans)return;//最优性剪枝
    if(miller(x)){ans=x;return;}
    ll y=Pollard(x);while(x%y==0)x/=y;//判定质数 更新答案
    find(y);find(x);//继续寻找
}
int main()
{
    T=(int)read();
    while(T--)
    {
        n=read();ans=1;find(n);
        if(ans==n){printf("Prime\n");continue;}
        printf("%lld\n",ans);
    }
    return 0;
}
