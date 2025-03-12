/// Write a program to find the root of the equation x3 – 9x + 1 = 0, correct to 3 decimal places, by using the bisection method.
#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x * x - 9 * x + 1;
}

double bisection(double a, double b, double tolerance) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval [a, b]" << endl;
        return NAN;
    }
    double c;
    while ((b - a) >= tolerance) {
        c = (a + b) / 2;
        if (f(c) == 0.0) break;
        else if (f(c) * f(a) < 0) b = c;
        else a = c;
    }
    return c;
}

int main() {
    double a = 2, b = 3; // Interval [a, b]
    double tolerance = 0.001;
    double root = bisection(a, b, tolerance);
    cout << "Root: " << fixed << setprecision(5) << root << endl;
    return 0;
}
