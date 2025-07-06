#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    return log10(x);
}

int main()
{
    double a,b;
    cout<<"enter low a:";//1
    cin>>a;
    cout<<"enter high b:";//5
    cin>>b;
    cout<<"Step Size N:";
    int n;cin>>n;

    double h = (b - a) / n;
    double sum = 0.0;

    // Compute f(x0) and f(xn)
    sum += f(a) + f(b);

    // Compute 2*f(xi) for i = 1 to n-1
    for (int i = 1; i < n; i++)
    {
        double y = a + i * h;
        sum += 2 * f(y);
    }

    double ans = (h / 2.0) * sum;

    cout << fixed << setprecision(4)<<"Approximate value of the integral I: " << ans << endl;
}
