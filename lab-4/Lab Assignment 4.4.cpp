/*
Write a program to solve the following Differential Equation by using Euler’s method.
        dy / dx = x3 + y,  y (0) = 1. Compute y (0.02) taking h = 0.01.
*/
#include <bits/stdc++.h>

using namespace std;

double f(double x, double y)
{
    return x*x*x + y;
}

int main()
{
    //double x = 0, y = 1, h = 0.01;
    double x, y, h, point;
    cout << "Enter x0 :";
    cin >> x;
    cout << "Enter y0 :";
    cin >> y;
    cout << "Enter h:";
    cin >> h;
    cout << "Enter x to compute y(x):";
    cin >> point;
    while (x < 0.02)
    {
        y = y + h * f(x, y);
        x += h;
    }
    cout << "y(0.02) using Euler's method: " << y << endl;
    return 0;
}
