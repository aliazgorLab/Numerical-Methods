#include <bits/stdc++.h>
using namespace std;

// Function to evaluate a polynomial using Horner's Method
// a[] stores coefficients from highest degree down to constant term
// n is the degree of the polynomial (total coefficients = n + 1)
double evaluateHorner(double a[], int n, double x) {
    double result = a[0];
    for (int i = 1; i <= n; i++) {
        result = result * x + a[i];
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the degree of the polynomial: ";
    cin >> n;

    double a[n + 1];
    cout << "Enter " << n + 1 << " coefficients (from highest power to constant): ";
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    double x;
    cout << "Enter the value of x: ";
    cin >> x;

    double value = evaluateHorner(a, n, x);

    cout << "f(" << x << ") = " << value << endl;

    return 0;
}
