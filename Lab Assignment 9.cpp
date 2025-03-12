///Write a program to find the quotient polynomial q(x) such that p(x) = (x - 2) q(x) where the polynomial p(x) = x 3 - 5x 2 + 10x - 8 = 0 has a root at x = 2.
#include <bits/stdc++.h>
using namespace std;

vector<double> syntheticDivision(const vector<double>& coefficients, double root) {
    vector<double> res(coefficients.size() - 1);
    double carry = 0;
    for (size_t i = 0; i < coefficients.size() - 1; ++i) {
        carry = coefficients[i] + carry * root;
        res[i] = carry;
    }

    return res;
}
int main() {
    // Coefficients of p(x) = x^3 - 5x^2 + 10x - 8
    vector<double> coefficients = {1, -5, 10, -8};
    double root = 2;
    vector<double> quotient = syntheticDivision(coefficients, root);

    cout << "The quotient polynomial q(x) is: ";
    for (size_t i = 0; i < quotient.size(); ++i) {
        if (i == 0) {
            cout << quotient[i] << "x^" << quotient.size() - i - 1;
        } else if (i == quotient.size() - 1) {
            cout << " + " << quotient[i];
        } else {
            cout << " + " << quotient[i] << "x^" << quotient.size() - i - 1;
        }
    }
    cout << endl;

    return 0;
}
