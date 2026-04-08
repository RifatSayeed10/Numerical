#include<bits/stdc++.h>
using namespace std;

#define f(x) (1/(1+x*x))

int main () {

    double a ,b  ,n  ,xn,h        ;

cout << " lower a and upper b " ; cin>>a>>b;

cout <<"Enter the range : " ; cin>>n;

double f1 = f(a) + f(b) ;

h=(b-a)/n;
for (int i =1 ; i<n; i++) {

    xn=a+i*h;

    f1 =f1 + 2*f(xn);

}

f1 =f1 * (h/2);

cout<< f1;

}