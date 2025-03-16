///Write a program to find the root of the equation x3 - x + 2 = 0, correct to 3 decimal places, by using false position method
#include<bits/stdc++.h>
using namespace std;


double f(double x) {
    return pow(x, 3) - x + 2;
}

 double falsePosition(double a, double b, double tolerance) {
    double c = a;
    int iteration = 0;

    cout << "Iteration\t a\t\t b\t\t c\t\t f(c)" << endl;
    cout << "--------------------------------------------------------------" << endl;

    while (abs(f(c)) >= tolerance) {

        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        cout << iteration + 1 << "\t\t " << fixed << setprecision(6) << a << "\t " << b << "\t " << c << "\t " << f(c) << endl;
        if (f(c) == 0.0) {
            break;
        }
        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        iteration++;
    }

    return c;
}

int main() {
    double a = -2.0;
    double b = 2.0;
    double tolerance = 0.001;
    double root = falsePosition(a, b, tolerance);
    cout << "\nThe root of the equation x^3 - x + 2 = 0 is approximately: " << fixed << setprecision(3) << root << endl;

    return 0;
}
