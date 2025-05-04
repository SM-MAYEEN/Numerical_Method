/*The following values of f (x) are given.
x 1 2 3 4 5
y = f(x) 1 8 27 64 125
Write a program to find the values of x for which f (x) = 85 by using Lagrange’s inverse
interpolation formula.
*/
#include <bits/stdc++.h>
using namespace std;

#define dl double

dl fun(dl y, const vector<dl>& xvals, const vector<dl>& yvals) {
    int n = xvals.size();
    dl res = 0;
    for (int i = 0; i < n; i++) {
        dl term = xvals[i];
        for (int j = 0; j < n; j++) {
            if (j != i) term *= (y - yvals[j]) / (yvals[i] - yvals[j]);
        }
        res += term;
    }
    return res;
}

int main() {
    int n;
    cout << "Enter number of data Entries: ";
    cin >> n;
    vector<dl> xvals(n), yvals(n);
    cout << "Enter x values: ";
    for (int i = 0; i < n; i++) cin >> xvals[i];
    cout << "Enter y values: ";
    for (int i = 0; i < n; i++) cin >> yvals[i];
    dl y;
    cout << "Enter y to find x: ";
    cin >> y;
    cout << "x for f(x)=" << y << " is " << fun(y, xvals, yvals) << endl;
    return 0;
}
