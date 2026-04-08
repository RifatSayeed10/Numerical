#include<bits/stdc++.h>
#define f(x) 1/(1+x*x)
using namespace std;
int main()


{

    double a ,b  ,n  ,xi,h        ;

cout << " lower a and upper b " ; cin>>a>>b;

cout <<"Enter the range : " ; cin>>n;

double integral = f(a) + f(b);

h=(b-a)/n;

for (int i=1; i <n ; i++){

     xi=a+i*h;

     if (i%2==0)
     integral=integral + 2*f(xi);
     else
     integral=integral + 4*f(xi);
}
        
integral=integral*(h/3);

cout <<integral;

}