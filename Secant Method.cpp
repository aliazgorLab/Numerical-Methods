#include <bits/stdc++.h>
using namespace std;

// The polynomial function: f(x) = x^3 - 5x^2 - 29
double f(double x) {
    return (x * x * x) - 5 * (x * x) - 29;
}

// Function to find the root using the Secant Method
double secant(double x0, double x1, double tolerance = 0.0001, int maxIterations = 100) {
    double x2 = x1;

    for (int i = 0; i < maxIterations; i++) {
        double f0 = f(x0);
        double f1 = f(x1);

        // Guard against division by zero
        if (fabs(f1 - f0) < 1e-12) {
            cout << "Mathematical error: Division by zero." << endl;
            return x2;
        }

        // Secant formula
        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);

        // Check if the change is within tolerance
        if (fabs(x2 - x1) < tolerance) {
            return x2;
        }

        // Update guesses for next iteration
        x0 = x1;
        x1 = x2;
    }

    return x2;
}

int main() {
    double x0, x1;

    cout << "Enter first initial guess (x0): ";
    cin >> x0;

    cout << "Enter second initial guess (x1): ";
    cin >> x1;

    double root = secant(x0, x1);

    cout << fixed << setprecision(3);
    cout << "Root: " << root << endl;

    return 0;
}
