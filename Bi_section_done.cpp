#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return 3*x + sin(x) - exp(x);
}

int main() {
    double a, b, c, tol;

    cout << "Enter a, b: ";
    cin >> a >> b;

    cout << "Enter tolerance: ";
    cin >> tol;

    if (f(a) * f(b) > 0) {
        cout << "Invalid interval!";
        return 0;
    }

    do {
        c = (a + b) / 2;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

    } while (fabs(f(c)) > tol);

    cout << "Root = " << c;

    return 0;
}
