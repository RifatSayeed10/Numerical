#include<bits/stdc++.h>
using namespace std ;
double determinant (double a1 , double a2 , double a3 , double b1 , double b2 , double b3 , double c1 , double c2 , double c3) {
  double result = a1 * (b2*c3 - b3 * c2) - b1 * (a2 * c3 - c2 * a3) + c1 * (a2*b3 - b2*a3) ;
  return result ;
}
int main()
{
  cout << "Enter the number of points : " ;
  int n ; cin>>n ;
  cout << "Enter point (x y ) : " ;
  double sumX = 0 , sumY = 0 , sumX2 = 0 , sumX3 = 0 , sumX4 = 0 , sumXY = 0 , sumX2Y = 0 ;
  for (int i = 0 ; i < n ; i++) {
    double x , y ; cin>>x>>y ;
    sumX += x ; sumY += y ;
    sumX2 += x*x ; sumX3 += (x*x*x) ; sumX4 += (x*x*x*x) ;
    sumXY += (x*y) ; sumX2Y += (x*x*y) ;
  }

  
  double Da = determinant (sumY , sumXY , sumX2Y , sumX , sumX2 , sumX3 , sumX2 , sumX3 , sumX4 ) ;
  double Db = determinant (n , sumX , sumX2 ,sumY , sumXY , sumX2Y , sumX2 , sumX3 , sumX4  ) ;
  double Dc = determinant (n , sumX , sumX2 , sumX , sumX2 , sumX3 ,sumY , sumXY , sumX2Y ) ;
  double D = determinant (n , sumX , sumX2 ,sumX , sumX2 , sumX3 ,sumX2 , sumX3 , sumX4) ;
  
  double a = Da / D ;
  double b = Db / D ;
  double c = Dc / D ;

  cout << fixed << setprecision (4) ; 
  cout << "The parabola function : y = " << a << " + " << b << "x + " << c << "x2" << endl ;
  return 0 ;
}