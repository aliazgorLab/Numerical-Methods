#include <bits/stdc++.h>
using namespace std;

// The polynomial function: f(x) = x^3 - 9x + 1
double f(double x) {
    return (x * x * x) - 9 * x + 1;
}

// Function to find root using Bisection Method
double bisection(double l, double h, double tolerance = 0.0001) {
    double m;

    while ((h - l) > tolerance) {
        m = (l + h) / 2.0;

        // If the midpoint is an exact root, terminate
        if (f(m) == 0.0) {
            break;
        }

        // Check which sub-interval contains the root
        if (f(l) * f(m) < 0) {
            h = m;
        } else {
            l = m;
        }
    }

    return (l + h) / 2.0;
}

int main() {
    double l, h;

    cout << "Enter lower guess (l): ";
    cin >> l;

    cout << "Enter upper guess (h): ";
    cin >> h;

    // Verify if root is bracketed: f(l) and f(h) must have opposite signs
    if (f(l) * f(h) >= 0) {
        cout << "Invalid interval! f(l) and f(h) must have opposite signs." << endl;
        return 0;
    }

    double root = bisection(l, h);

    cout << fixed << setprecision(3);
    cout << "Root: " << root << endl;

    return 0;
}
