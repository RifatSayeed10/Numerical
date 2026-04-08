#include<bits/stdc++.h>
using namespace std;

#define f(x) ((x)*(x)*(x) - 2*(x) - 5)

int main() {

    float x, h, d1, d2;

    cout << "Enter value of x: ";
    cin >> x;

    cout << "Enter value of h: ";
    cin >> h;

    // First derivative (central difference)
    d1 = (f(x+h) - f(x-h)) / (2*h);

    // Second derivative (central difference)
    d2 = (f(x+h) - 2*f(x) + f(x-h)) / (h*h);

    cout << "First derivative = " << d1 << endl;
    cout << "Second derivative = " << d2 << endl;

    return 0;
}