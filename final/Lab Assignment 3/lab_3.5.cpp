
#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x / (1 + x * x);
}

int main()
{
    double a,b;
    cout<<"enter low a:";//0
    cin>>a;
    cout<<"enter high b:";//1
    cin>>b;
    cout<<"Step Size N:";
    int n;cin>>n;

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        double xi = a + i * h;
        if (i % 3 == 0)
            sum += 2 * f(xi);
        else
            sum += 3 * f(xi);
    }

    double result = (3 * h / 8.0) * sum;
    cout << fixed << setprecision(4)<< "Approximate value of the integral: " << result << endl;

}
