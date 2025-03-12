
/// Write a program to find all the roots of the equation x 3 - 6x + 4 = 0, correct to 3 decimal places. [Use bisection method].
#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x * x - 6 * x + 4;
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
    double intervals[][2] = {{-3, -2}, {0, 1}, {2, 3}}; // Intervals for roots
    double tolerance = 0.001;
    for (auto& interval : intervals) {
        double root = bisection(interval[0], interval[1], tolerance);
        cout << "Root: " << fixed << setprecision(3) << root << endl;
    }
    return 0;
}
