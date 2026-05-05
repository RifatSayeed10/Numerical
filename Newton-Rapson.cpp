#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return cos(x) - x * exp(x);
}

double df(double x) {
    return -sin(x) - exp(x) - x * exp(x);
}

int main() {
    double x, tol, x1;

    cout << "Enter initial guess: ";
    cin >> x;

    cout << "Enter tolerance: ";
    cin >> tol;

    do {
        x1 = x - f(x) / df(x);
        x = x1;
    } while (fabs(f(x)) > tol);

    cout << "Root = " << x;

    return 0;
}
