#include<bits/stdc++.h>
using namespace std;

#define f(x) ((x)*(x)*(x) - 2*(x) - 5)

int main () {

    float a, b, f1, f2, t, c, f3, e;

    cout << "Enter the value of a and b : ";
    cin >> a >> b;

    f1 = f(a);
    f2 = f(b);

    if (f1 * f2 > 0) {
        cout << "There is no root between a and b";
        return 0;
    }

    cout << "Enter the tolerance value : ";
    cin >> t;

    do {
        // False Position formula
        c = (a * f2 - b * f1) / (f2 - f1);

        f3 = f(c);

        if (f1 * f3 < 0) {
            b = c;
          
        }
        else {
            a = c;
            
        }

        e = fabs(b - a);

    } while (abs(f3) > t);

    cout << "The approx root " << c << endl;

}