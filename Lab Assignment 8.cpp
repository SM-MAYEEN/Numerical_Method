///Write a program to find the root of the equation x 3 – 5x2 –29 = 0, correct to 3 decimal places, by using secant method.
#include<bits/stdc++.h>
using namespace std;

double f(double x) {
    return ((x * x * x) - (5 * x * x) - 29);
}
double secant(double x0, double x1, double tolerance) {
    double x2;
    while (abs(f(x1)) > tolerance) {
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
    }
    return x1;
}

int main() {
    double x0 = 5, x1 = 6;
    double tolerance = 0.001;
    double root = secant(x0, x1, tolerance);
    cout << "Root: " << fixed << setprecision(5) << root << endl;
    return 0;
}
