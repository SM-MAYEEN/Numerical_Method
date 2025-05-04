/*
The following values of f (x) are given.
     x              1     2     3       4        5
   y = f(x)     1     8    27     64     125
Write a program to find difference table for the above values.

*/


#include <bits/stdc++.h>
using namespace std;

#define dl double

void fun(const vector<dl>x, const vector<dl>y)
{
    int n = x.size();
    vector<vector<dl>> tab(n, vector<dl>(n));
    for (int i = 0; i < n; i++) tab[i][0] = y[i];
    for (int j = 1; j < n; j++)
        for (int i = 0; i < n - j; i++)
            tab[i][j] = tab[i+1][j-1] - tab[i][j-1];
    cout << "x\tf(x)\t";
    for (int i = 1; i < n; i++) cout << "delY" << i << "\t";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << "\t";
        for (int j = 0; j < n - i; j++)
            cout << tab[i][j] << "\t";
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter number of data Entries: ";
    cin >> n;
    vector<dl> x(n), y(n);
    cout << "Enter x values: ";
    for (int i = 0; i < n; i++) cin >> x[i];
    cout << "Enter y values: ";
    for (int i = 0; i < n; i++) cin >> y[i];
    cout << endl;
    fun(x, y);
    return 0;
}
