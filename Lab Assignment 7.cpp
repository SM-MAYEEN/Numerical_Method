///Write a program to find the root of the equation x3 - x + 2 = 0, correct to 3 decimal places, by using false position method
#include<bits/stdc++.h>
using namespace std;


double f(double x) {
    return x * x * x - x + 2;
}

double falsePosition(double x1, double x2, double tolerance) {
    if (f(x1) * f(x2) >= 0) {
        cout << "Invalid interval [x1, x2]. f(x1) and f(x2) must have opposite signs." << endl;
        return NAN;
    }

    double x0;
    double x0_prev;
    int iterations = 0;

    do {
        x0_prev = x0;
        x0 = x1 - (f(x1) * (x2 - x1)) / (f(x2) - f(x1));
        if (f(x0) == 0.0) {
            break;
        }

        if (f(x0) * f(x1) < 0) {
            x2 = x0;
        } else {
            x1 = x0;
        }

        iterations++;
    }
    while (fabs(x0 - x0_prev) >= tolerance);

    cout << "Number of iterations: " << iterations << endl;
    return x0;
}

int main() {
    double x1, x2, tolerance;
    cout << "Enter the interval [x1, x2]: ";
    cin >> x1 >> x2;

    tolerance = 1e-4;
     double root = falsePosition(x1, x2, tolerance);
     if (!isnan(root)) {
        cout << "The root of the equation x^3 - x + 2 = 0 is: "
             << fixed << setprecision(5) << root << endl;
    }

    return 0;
}
