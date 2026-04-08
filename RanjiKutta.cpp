#include<bits/stdc++.h>
#define f(x,y) (x+y*y)
using namespace std;
int main()
{
     cout<<fixed<<setprecision(6);
    float x0,y0,xn,h,n;
    float yn,k1,k2,k3,k4,k;
    cout<<"Enter the value of x0 and y0:";cin>>x0>>y0;
    cout<<"Enter the value of n:";cin>>n;
    cout<<"Enter the value of xn :";cin>>xn;
     h=(xn-x0)/n;
    for(int i=0;i<n;i++)
    {
        k1=h*f(x0,y0);
        k2=h*f((x0+h/2),(y0+k1/2));
        k3=h*f((x0+h/2),(y0+k2/2));
        k4=h*f((x0+h),(y0+k3));
        k=(k1+2*k2+2*k3+k4)/6;
        yn=y0+k;

        y0=yn;
        x0=x0+h;

    }

    cout<<" X= "<<xn<<" Y= "<<yn;
    return 0;

}