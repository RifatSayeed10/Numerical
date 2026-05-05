#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return sin(x) - log(x) + exp(x);
}

int main() {
    double a, b, h, sum;
    int n;

    cout << "Enter lower limit: ";
    cin >> a;

    cout << "Enter upper limit: ";
    cin >> b;

    cout << "Enter number of intervals: ";
    cin >> n;

    h = (b - a) / n;

    sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        sum += 2 * f(a + i * h);
    }

    double result = (h / 2) * sum;

    cout << "Integral value = " << result;

    return 0;
}
