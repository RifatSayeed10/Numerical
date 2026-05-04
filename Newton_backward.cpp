#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    float x[10], y[10];

    cout << "Enter number of n : ";
    cin >> n;

    cout << "Enter values x and y : ";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    float t, h, u, d, p = 1.0;

    cout << "Enter target: ";
    cin >> t;

    h = x[1] - x[0];

    // Backward formula uses last x
    u = (t - x[n - 1]) / h;

    // Start from last y
    d = y[n - 1];

    for (int i = 1; i < n; i++) {

        // Backward differences
        for (int j = n - 1; j >= i; j--) {
            y[j] = y[j] - y[j - 1];
        }

        p = p * (u + i - 1) / i;

        d = d + p * y[n - 1];
    }

    cout << "X = " << t << " y = " << d;

    return 0;
}
