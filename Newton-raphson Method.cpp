#include <bits/stdc++.h>
using namespace std;

// The polynomial function: f(x) = x^3 - 6x + 4
double f(double x) {
    return (x * x * x) - 6 * x + 4;
}

// Derivative of the function: f'(x) = 3x^2 - 6
double d(double x) {
    return 3 * x * x - 6;
}

// Function to find the root using Newton-Raphson Method
double newtonRaphson(double x0, double tolerance = 0.0001, int maxIterations = 100) {
    double x = x0;

    for (int i = 0; i < maxIterations; i++) {
        double df = d(x);

        // Avoid division by zero if derivative is zero
        if (fabs(df) < 1e-12) {
            cout << "Mathematical error: Derivative is zero." << endl;
            return x;
        }

        double x_next = x - f(x) / df;

        // Check if the change is within tolerance
        if (fabs(x_next - x) < tolerance) {
            return x_next;
        }

        x = x_next;
    }

    return x;
}

int main() {
    double x0;

    cout << "Enter initial guess (x0): ";
    cin >> x0;

    double root = newtonRaphson(x0);

    cout << fixed << setprecision(3);
    cout << "Root: " << root << endl;

    return 0;
}
