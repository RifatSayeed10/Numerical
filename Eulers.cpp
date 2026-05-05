#include <iostream>
#include <iomanip>
using namespace std;

float f(float x, float y) {
    return (y - x) / (y + x);
}

int main() {
    float x0, y0, h, xn;

    cout << "Enter x0, y0: ";
    cin >> x0 >> y0;

    cout << "Enter step size h: ";
    cin >> h;

    cout << "Enter final x: ";
    cin >> xn;

    float x = x0, y = y0;

    cout << fixed << setprecision(6);
    cout << "x\t\ty\n";

    while (x < xn) {
        cout << x << "\t" << y << endl;
        y = y + h * f(x, y);
        x = x + h;
    }

    cout << xn << "\t" << y << endl;
    cout << "\nAnswer y(" << xn << ") = " << y;

    return 0;
}
