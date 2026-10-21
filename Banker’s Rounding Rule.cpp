#include <bits/stdc++.h>
using namespace std;

// Function to round off a number to n significant figures using Banker's Rule
string roundBankers(string s, int n) {
    int count = 0;
    int pos = -1;

    // 1. Locate the position of the n-th significant digit
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            continue;
        }
        if (s[i] != '0' || count > 0) {
            count++;
            if (count == n) {
                pos = i;
                break;
            }
        }
    }

    // If n is larger than the available digits, return as is
    if (pos == -1) {
        return s;
    }

    // 2. Find the next deciding digit (skip decimal if in between)
    int next = pos + 1;
    if (next < s.size() && s[next] == '.') {
        next++;
    }

    // 3. Apply Banker's Rule (round half to even)
    if (next < s.size()) {
        if (s[next] > '5') {
            s[pos]++;
        } 
        else if (s[next] == '5') {
            // Increment only if the preceding digit is odd
            if ((s[pos] - '0') % 2 != 0) {
                s[pos]++;
            }
        }
    }

    // 4. Extract the rounded prefix up to pos
    string result = "";
    for (int i = 0; i <= pos; i++) {
        result += s[i];
    }

    // Pad trailing zeros if n requested more figures than present
    while (count < n) {
        result += '0';
        count++;
    }

    return result;
}

int main() {
    string number;
    int n;

    cout << "Enter the number: ";
    cin >> number;

    cout << "Enter the number of significant figures (n): ";
    cin >> n;

    string rounded = roundBankers(number, n);

    cout << "Rounded value: " << rounded << endl;

    return 0;
}
