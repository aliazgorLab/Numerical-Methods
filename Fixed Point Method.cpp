#include <bits/stdc++.h>
using namespace std;

// Rearranged function x = g(x)
// Example equation: x^3 - x - 1 = 0  =>  x = (x + 1)^(1/3)
double g(double x) {
    return cbrt(x + 1);
}

// Function to find the root using Fixed Point Iteration Method
double fixedPoint(double x0, double tolerance = 0.0001, int maxIterations = 100) {
    double x1;

    for (int i = 0; i < maxIterations; i++) {
        x1 = g(x0);

        // Check if the difference between successive approximations is within tolerance
        if (fabs(x1 - x0) < tolerance) {
            return x1;
        }

        x0 = x1;
    }

    return x1;
}

int main() {
    double x0;

    cout << "Enter initial guess (x0): ";
    cin >> x0;

    double root = fixedPoint(x0);

    cout << fixed << setprecision(3);
    cout << "Root: " << root << endl;

    return 0;
}
