/*
Write a program to solve the following Differential Equation by using Runge – Kutta method.
       dy / dx = x + y, y (0) = 1.  Compute y (0.1) and y (0.2)  taking h = 0.1.
*/
#include<bits/stdc++.h>

using namespace std;

double f(double x, double y)
{
    return x + y;
}

int main()
{
    //  x = 0, y = 1, h = 0.1;
    double x, y,h,point;
    cout<<"Enter x0 :";
    cin>>x;
    cout<<"Enter y0 :";
    cin>>y;
    cout<<"Enter h:";
    cin>>h;
    cout<<"Enter x to compute y(x):";
    cin>>point;

    for (int i = 0; i < 2; i++)
    {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h/2, y + k1/2);
        double k3 = h * f(x + h/2, y + k2/2);
        double k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
        x += h;

        cout << "y(" << x << ") = " << y << endl;
    }

    return 0;
}
