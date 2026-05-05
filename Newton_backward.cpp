#include <iostream>
using namespace std;

int main() {
    int n;
    double x[20], y[20];

    cout << "Enter number of data points: ";
    cin >> n;

    cout << "Enter x and y values:\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    double target;
    cout << "Enter target year: ";
    cin >> target;

    double h = x[1] - x[0];
    double u = (target - x[n - 1]) / h;

    double ans = y[n - 1];
    double p = 1;

    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            y[j] = y[j] - y[j - 1];
        }

        p = p * (u + i - 1) / i;
        ans = ans + p * y[n - 1];
    }

    cout << "Population = " << ans << " thousand";

    return 0;
}
