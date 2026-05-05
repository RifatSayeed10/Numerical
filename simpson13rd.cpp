#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return sqrt(1 - x*x);
}

int main() {
    double a, b, h, sum;
    int n;

    cout << "Enter lower limit: ";
    cin >> a;

    cout << "Enter upper limit: ";
    cin >> b;

    cout << "Enter number of intervals even n: ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "n must be even!";
        return 0;
    }

    h = (b - a) / n;
    sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        if (i % 2 == 0)
            sum += 2 * f(a + i * h);
        else
            sum += 4 * f(a + i * h);
    }

    double result = (h / 3) * sum;

    cout << "Integral value = " << result;

    return 0;
}
