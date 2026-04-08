#include<bits/stdc++.h>
using namespace std;

#define f(x) x*x*x - 2*x - 5

int main () {

    float a ,b,f1,f2,t,m, f3,e;
 cout<< "Enter the value of a and b : "; cin>>a>>b;

 f1=f(a);
 f2=f(b);

 if (f1*f2 >0){
    cout<<"There is no root between a and b";
    return 0;
 }
 
 cout<<"Enter the tolarence value : "; cin>>t;

 do {
    
      m=(a+b)/2;
      f3=f(m);

    if (f1*f3<0)
       b=m;
    else
       a=m;

      e=abs(b-a);
       
    }
    while (e>t);

    cout << "The approx root "<<m<<endl;

}