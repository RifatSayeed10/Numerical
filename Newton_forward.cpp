#include<bits/stdc++.h>
using namespace std ;

int main () {

float n , x[10], y[10];
cout <<"Enter number of n : " ; cin>> n;

cout <<"Enter values x and y : " ; 

for (int i=0 ; i<n ; i++) {

    cin>>x[i]>>y[i];

}

float t, h, u ,d ,p=1.00  ;

cout <<"Enter target: " ; cin>> t;




h= (x[1]-x[0]);

u=(t-x[0])/h;

d=y[0];

for (int i=1 ; i<n ; i++) {

    for (int j=0;j<n-i;j++ ){

        y[j]=y[j+1]-y[j];
       
    }

    p= p* (u-i+1)/i;

d=d+ p*y[0];

}



cout<< "X = " << t << " y = " << d ;


}