#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    double L, alpha, T;
    int nx, nt;

    cout << "Enter length L: ";
    cin >> L;

    cout << "Enter alpha: ";
    cin >> alpha;

    cout << "Enter final time T: ";
    cin >> T;

    cout << "Enter number of space steps nx: ";
    cin >> nx;

    cout << "Enter number of time steps nt: ";
    cin >> nt;

    double dx = L / nx;
    double dt = T / nt;

    double r = (alpha * alpha * dt) / (dx * dx);

    if (r > 0.5) {
        cout << "Warning: Method may be unstable because r > 0.5\n";
    }

    vector<double> u(nx + 1), unew(nx + 1);

    // Initial condition: u(x,0) = e^(-x) + sin(x)
    for (int i = 0; i <= nx; i++) {
        double x = i * dx;
        u[i] = exp(-x) + sin(x);
    }

    // Periodic boundary condition
    u[nx] = u[0];

    // Time marching
    for (int n = 0; n < nt; n++) {
        for (int i = 1; i < nx; i++) {
            unew[i] = u[i] + r * (u[i + 1] - 2 * u[i] + u[i - 1]);
        }

        // Periodic boundary condition
        unew[0] = u[0] + r * (u[1] - 2 * u[0] + u[nx - 1]);
        unew[nx] = unew[0];

        u = unew;
    }

    cout << "\nSolution at time T = " << T << ":\n";
    cout << "x\t\tu(x,T)\n";

    for (int i = 0; i <= nx; i++) {
        double x = i * dx;
        cout << fixed << setprecision(6) << x << "\t" << u[i] << endl;
    }

    return 0;
}
