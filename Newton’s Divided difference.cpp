#include <bits/stdc++.h>
using namespace std;

// Function to calculate interpolated value using Newton's Divided Difference formula
double newtonDividedDifference(double x[], double y[], int n, double value) {
    double table[n][n];

    // Initialize the first column with y values (0th divided differences)
    for (int i = 0; i < n; i++) {
        table[i][0] = y[i];
    }

    // Build the divided difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    // Calculate interpolated value using the first row coefficients
    double result = table[0][0];
    double term = 1.0;

    for (int j = 1; j < n; j++) {
        term *= (value - x[j - 1]);
        result += term * table[0][j];
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of data points (n): ";
    cin >> n;

    double x[n], y[n];

    cout << "Enter the values of x: ";
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

    double result = newtonDividedDifference(x, y, n, value);

    cout << fixed << setprecision(4);
    cout << "Interpolated value at x = " << value << " is: " << result << endl;

    return 0;
}
