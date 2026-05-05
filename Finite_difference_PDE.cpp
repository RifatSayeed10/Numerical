#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

#define PI 3.14159265358979323846

int main() {
    int nx, nt, choice;
    double L, Tmax, alpha, dx, dt, r;

    cout << "\n=== Explicit Finite Difference Method for 1D Heat Equation ===\n\n";

    cout << "Enter length of domain (L)          : ";
    cin >> L;

    cout << "Enter maximum time (Tmax)           : ";
    cin >> Tmax;

    cout << "Enter number of space divisions (nx): ";
    cin >> nx;

    cout << "Enter number of time steps (nt)     : ";
    cin >> nt;

    cout << "Enter thermal diffusivity (alpha)   : ";
    cin >> alpha;

    dx = L / nx;
    dt = Tmax / nt;
    r = alpha * alpha * dt / (dx * dx);

    vector<vector<double>> u(nt + 1, vector<double>(nx + 1, 0.0));

    cout << "\nChoose Initial Condition:\n";
    cout << "1. u(x,0) = sin(pi*x/L)\n";
    cout << "2. u(x,0) = x*(L - x)\n";
    cout << "3. u(x,0) = exp(-x)\n";
    cout << "Enter choice: ";
    cin >> choice;

    // Initial condition
    for (int i = 0; i <= nx; i++) {
        double x = i * dx;

        if (choice == 1)
            u[0][i] = sin(PI * x / L);
        else if (choice == 2)
            u[0][i] = x * (L - x);
        else
            u[0][i] = exp(-x);
    }

    // Boundary conditions: u(0,t) = u(L,t) = 0
    for (int j = 0; j <= nt; j++) {
        u[j][0] = 0.0;
        u[j][nx] = 0.0;
    }

    // Explicit finite difference loop
    for (int j = 0; j < nt; j++) {
        for (int i = 1; i < nx; i++) {
            u[j + 1][i] =
                u[j][i] + r * (u[j][i - 1] - 2 * u[j][i] + u[j][i + 1]);
        }
    }

    // Display final result
    cout << fixed << setprecision(4);
    cout << "\nSolution at t = " << Tmax << " (Final Time):\n";
    cout << left << setw(10) << "x" << setw(15) << "u(x,Tmax)" << endl;
    cout << "----------------------------------------\n";

    int step = nx / 10;
    if (step == 0) step = 1;

    cout << setprecision(8);

    for (int i = 0; i <= nx; i += step) {
        double x = i * dx;
        cout << left << setw(10) << setprecision(4) << x
             << setw(15) << setprecision(8) << u[nt][i] << endl;
    }

    cout << "\nStability Parameter (r) = " << setprecision(4) << r;

    if (r > 0.5)
        cout << " -> WARNING: Unstable! Reduce dt or increase nt.\n";
    else
        cout << " -> Stable\n";

    return 0;
}
