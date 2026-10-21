#include <bits/stdc++.h>
using namespace std;

// The polynomial function: f(x) = x^3 - x + 2
double f(double x) {
    return (x * x * x) - x + 2;
}

// Function to find the root using False Position (Regula Falsi) Method
double falsePosition(double l, double h, int maxIterations = 100) {
    double m = l;

    for (int i = 0; i < maxIterations; i++) {
        // False Position formula
        m = (l * f(h) - h * f(l)) / (f(h) - f(l));

        // If m is an exact root, break early
        if (fabs(f(m)) < 1e-6) {
            break;
        }

        // Narrow the interval
        if (f(l) * f(m) < 0) {
            h = m;
        } else {
            l = m;
        }
    }

    return m;
}

int main() {
    double l, h;

    cout << "Enter lower guess (l): ";
    cin >> l;

    cout << "Enter upper guess (h): ";
    cin >> h;

    // Check if the root is bracketed
    if (f(l) * f(h) >= 0) {
        cout << "Invalid interval! f(l) and f(h) must have opposite signs." << endl;
        return 0;
    }

    double root = falsePosition(l, h);

    cout << fixed << setprecision(3);
    cout << "Root: " << root << endl;

    return 0;
}
