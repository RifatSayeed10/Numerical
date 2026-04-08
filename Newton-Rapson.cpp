#include<bits/stdc++.h>
using namespace std;

#define f(x) x*x*x - 2*x -5
#define df(x) 3*x*x -2

int main () {
 float x0,t  , x  ,f,df,f1   ;

cout<<"Enter the guess value and t : " ; cin>>x0>>t;



do {
    f=f(x0);
    df = df(x0);

     x=x0-(f/df);
     x0=x;
     f1=f(x);
} while (abs(f1)>t);

cout<<"approx root : "<< x;

}