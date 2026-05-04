#include <iostream>
#include <iomanip>
using namespace std;

// Change this function according to your differential equation
float f(float x, float y) {
    return x - y;                 // Example: dy/dx = x - y
    // return -2*x*y;
    // return (x - y)/(x + y);
}

int main() {
    float x0, y0, h, xn, x, y;
    int n, i;

    cout << "\n=== Euler's Method for Solving ODE ===\n\n";

    cout << "Enter initial value of x (x0) : ";
    cin >> x0;

    cout << "Enter initial value of y (y0) : ";
    cin >> y0;

    cout << "Enter step size (h)          : ";
    cin >> h;

    cout << "Enter final value of x (xn)  : ";
    cin >> xn;

    n = (xn - x0) / h;   // Number of steps

    x = x0;
    y = y0;

    cout << "\n" << left << setw(10) << "x" << setw(15) << "y(x)" << endl;
    cout << "-----------------------------------\n";

    cout << fixed << setprecision(4)
         << left << setw(10) << x
         << setprecision(6) << setw(15) << y << endl;

    for (i = 1; i <= n; i++) {
        y = y + h * f(x, y);   // Euler formula
        x = x + h;

        cout << fixed << setprecision(4)
             << left << setw(10) << x
             << setprecision(6) << setw(15) << y << endl;
    }

    cout << "-----------------------------------\n";
    cout << fixed << setprecision(4);
    cout << "Approximate value of y(" << xn << ") = ";
    cout << fixed << setprecision(8) << y << endl;

    return 0;
}
