
#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return exp(sin(x));
}

int main()
{
//    double a,b;
//    cout<<"enter low a:";//1
//    cin>>a;
//    cout<<"enter high b:";//5
//    cin>>b;
    cout<<"Step Size N:";
    int n;cin>>n;

    double a = 0.0, b = M_PI / 2.0;//pi/2
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        double y = a + i * h;
        if (i % 2 == 0)
            sum += 2 * f(y);
        else
            sum += 4 * f(y);
    }

    double ans = (h / 3.0) * sum;

    cout << fixed << setprecision(4)<<"Approximate value of the integral: " << ans << endl;

}
