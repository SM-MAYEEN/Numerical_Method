/*
The following values of f (x) are given.
x 1 2 3 4 5
y = f(x) 1 8 27 64 125
Write a program to find the values of y when x = 4.7 by using Newton&#39;s backward interpolation
formula.
*/
#include <bits/stdc++.h>
using namespace std;

#define dl double

dl fun(dl x, const vector<dl>& xvals, const vector<dl>& yvals) {
    int n = xvals.size();
    vector<vector<dl>> tab(n, vector<dl>(n));
    for (int i = 0; i < n; i++) tab[i][0] = yvals[i];
    for (int j = 1; j < n; j++)
        for (int i = n-1; i >= j; i--)
            tab[i][j] = tab[i][j-1] - tab[i-1][j-1];
    dl h = xvals[1] - xvals[0];
    dl u = (x - xvals.back()) / h;
    dl res = yvals.back(), term = 1;
    for (int i = 1; i < n; i++) {
        term *= (u + (i-1)) / i;
        res += term * tab[n-1][i];
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
    dl x;
    cout << "Enter x to find f(x): ";
    cin >> x;
    cout << "f(" << x << ") = " << fun(x, xvals, yvals) << endl;
    return 0;
}
