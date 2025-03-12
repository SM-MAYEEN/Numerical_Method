
///Write a program to find the root of the equation x3 - 6x + 4 = 0, correct to 3 decimal places, by using Newton-Raphson method.

#include<bits/stdc++.h>

using namespace std;


double f(double x) {
    return x * x * x - 6 * x + 4;
}

// Define the derivative of the function f'(x) = 3x^2 - 6
double f_prime(double x) {
    return 3 * x * x - 6;
}

 double newtonRaphson(double x0, double tolerance) {
    double x = x0;
    double h;

    do {
        h = f(x) / f_prime(x);
        x = x - h;
    } while (fabs(h) >= tolerance);

    return x; //  root
}

int main() {
    double x0, tolerance;
    cout << "Enter the initial guess (x0): ";
    cin >> x0;
    tolerance = 1e-4;
    double root = newtonRaphson(x0, tolerance);

    cout << "The root of the equation x^3 - 6x + 4 = 0 is: "
         << fixed << setprecision(5) << root << endl;

    return 0;
}
