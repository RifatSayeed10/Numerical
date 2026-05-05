#include <iostream>
#include <iomanip>
using namespace std;

double f(double x, double y) {
    return (y - x) / (y + x);
}

int main() {
    double x, y, h, xn;

    cout << "Enter x0: ";
    cin >> x;

    cout << "Enter y0: ";
    cin >> y;

    cout << "Enter h: ";
    cin >> h;

    cout << "Enter xn: ";
    cin >> xn;

    cout << fixed << setprecision(6);

    while (x < xn) {
        y = y + h * f(x, y);
        x = x + h;
    }

    cout << "y(" << xn << ") = " << y;

    return 0;
}
