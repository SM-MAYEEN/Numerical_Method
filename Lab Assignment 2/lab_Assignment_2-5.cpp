/*The following values of f (x) are given. Prepare the divided difference table for the following data
x 1 3 4 6 10
y = f(x) 0 18 58 190 920
Write a program to find the values of y when x = 2.7 by using Newtons divided difference formula.
*/
#include <bits/stdc++.h>
using namespace std;

#define dl double

dl fun(dl x, const vector<dl> &xvals, const vector<dl> &yvals)
{
    int n = xvals.size();
    vector<vector<dl>> tab(n, vector<dl>(n));
    for (int i = 0; i < n; i++)
        tab[i][0] = yvals[i];
    for (int j = 1; j < n; j++)
        for (int i = 0; i < n - j; i++)
            tab[i][j] = (tab[i + 1][j - 1] - tab[i][j - 1]) / (xvals[i + j] - xvals[i]);
    dl res = yvals[0], term = 1;
    for (int i = 1; i < n; i++)
    {
        term *= (x - xvals[i - 1]);
        res += term * tab[0][i];
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter number of data Entries: ";
    cin >> n;
    vector<dl> xvals(n), yvals(n);
    cout << "Enter x values: ";
    for (int i = 0; i < n; i++)
        cin >> xvals[i];
    cout << "Enter y values: ";
    for (int i = 0; i < n; i++)
        cin >> yvals[i];
    dl x;
    cout << "Enter x to find f(x): ";
    cin >> x;
    cout << "f(" << x << ") = " << fun(x, xvals, yvals) << endl;
    return 0;
}
