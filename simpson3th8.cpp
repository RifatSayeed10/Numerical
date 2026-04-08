#include<bits/stdc++.h>

#define f(x) 1/(1+x*x)
using namespace std;
int main()
{
    float a,b,n,h,ans,i;
    cout<<"Enter the limit:";cin>>a>>b;
    cout<<"Enter the value of n:";cin>>n;

    h=(b-a)/n;
    ans=f(a)+f(b);

    for(i=1;i<n;i++)
    {
        float k=a+i*h;
        if((int)i%3!=0)
            ans=ans+3*f(k);
        else
            ans= ans+2*f(k);
    }
    ans=ans*3*h/8;
    cout<<"The result :"<<ans;
    return 0;
}
