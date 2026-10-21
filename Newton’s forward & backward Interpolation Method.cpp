#include <bits/stdc++.h>
using namespace std;

// Function for Newton's Forward Interpolation
double newtonForward(double x[], double y[], int n, double value) {
    double diff[n][n];

    // Initialize the first column with y values
    for (int i = 0; i < n; i++) {
        diff[i][0] = y[i];
    }

    // Construct the forward difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }

    double h = x[1] - x[0];
    double u = (value - x[0]) / h;

    double result = diff[0][0];
    double u_term = 1.0;
    double fact = 1.0;

    // Apply Newton's Forward formula
    for (int j = 1; j < n; j++) {
        u_term *= (u - (j - 1));
        fact *= j;
        result += (u_term / fact) * diff[0][j];
    }

    return result;
}

// Function for Newton's Backward Interpolation
double newtonBackward(double x[], double y[], int n, double value) {
    double diff[n][n];

    // Initialize the first column with y values
    for (int i = 0; i < n; i++) {
        diff[i][0] = y[i];
    }

    // Construct the backward difference table
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }

    double h = x[1] - x[0];
    double v = (value - x[n - 1]) / h;

    double result = diff[n - 1][0];
    double v_term = 1.0;
    double fact = 1.0;

    // Apply Newton's Backward formula
    for (int j = 1; j < n; j++) {
        v_term *= (v + (j - 1));
        fact *= j;
        result += (v_term / fact) * diff[n - 1][j];
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of data points (n): ";
    cin >> n;

    double x[n], y[n];

    cout << "Enter the values of x (equally spaced): ";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter the corresponding values of y: ";
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    double value;
    cout << "Enter the value to interpolate: ";
    cin >> value;

    double forwardResult = newtonForward(x, y, n, value);
    double backwardResult = newtonBackward(x, y, n, value);

    cout << fixed << setprecision(4);
    cout << "\n--- Interpolation Results ---" << endl;
    cout << "Newton's Forward Interpolation:  " << forwardResult << endl;
    cout << "Newton's Backward Interpolation: " << backwardResult << endl;

    return 0;
}
