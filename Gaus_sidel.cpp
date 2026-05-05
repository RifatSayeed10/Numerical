#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int n;
    double a[20][21], x[20] = {0}, old[20];
    double tol, error;

    cout << "Enter number of equations: ";
    cin >> n;

    cout << "Enter augmented matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter tolerance: ";
    cin >> tol;

    cout << fixed << setprecision(6);

    do {
        for (int i = 0; i < n; i++)
            old[i] = x[i];

        for (int i = 0; i < n; i++) {
            double sum = a[i][n];

            for (int j = 0; j < n; j++) {
                if (i != j)
                    sum -= a[i][j] * x[j];
            }

            x[i] = sum / a[i][i];
        }

        error = 0;
        for (int i = 0; i < n; i++) {
            error = max(error, fabs(x[i] - old[i]));
        }

    } while (error > tol);

    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
