#include <bits/stdc++.h>
using namespace std;

int countSignificantDigits(string s) {
    int count = 0;
    bool decimal = false;

    // Remove leading sign (+ or -) if present
    if (!s.empty() && (s[0] == '+' || s[0] == '-')) {
        s = s.substr(1);
    }

    // Traverse the string
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            decimal = true;
        }
        else if (s[i] != '0') {
            count++;
        }
        else if (count > 0) {
            count++;
        }
    }

    // If there is no decimal point, trailing zeros are not significant
    if (!decimal) {
        while (!s.empty() && s.back() == '0') {
            count--;
            s.pop_back();
        }
    }

    return count;
}

int main() {
    string number;
    cout << "Enter a number: ";
    cin >> number;

    int result = countSignificantDigits(number);

    cout << "Number of significant digits: " << result << endl;

    return 0;
}
