#include<bits/stdc++.h>
using namespace std;

#define f(x) ((x)*(x)*(x) - 2*(x) - 5)

int main () {

    float x0, x1, x2, f0, f1, f2, t;

    cout << "Enter two initial guesses: ";
    cin >> x0 >> x1;

    cout << "Enter tolerance value: ";
    cin >> t;

    do {
        f0 = f(x0);
        f1 = f(x1);

        // Secant formula
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);

        f2 = f(x2);

        // update values
        x0 = x1;
        x1 = x2;

    } while (fabs(f2) > t);

    cout << "Approx root: " << x2 << endl;

}