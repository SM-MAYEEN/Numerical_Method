/// Write a program to evaluate a polynomial f(x) = x3 - 2x2 + 5x + 10  by using Horner's rule x = 5.
#include <bits/stdc++.h>

using namespace std;
#define ll long long

double horner(double coeff[], int n, double x) {
    double res = coeff[0];
    for (int i = 1; i < n; i++) {
        res = res * x + coeff[i];
    }
    return res;
}

int main() {
    double coeff[] = {1, -2, 5, 10}; // Coefficients for x^3 - 2x^2 + 5x + 10
    int n = sizeof(coeff) / sizeof(coeff[0]);
    double x = 5;
    cout << "Value of polynomial at x = " << x << " is: " << horner(coeff, n, x) << endl;
    return 0;
}
