/// Write a program to find all the roots of the equation x 3 - 6x + 4 = 0, correct to 3 decimal places. [Use Newton-Raphson method with deflation].
#include <bits/stdc++.h>
using namespace std;

double f(const vector<double> &v, double x)
{
    double res = 0;
    for (size_t i = 0; i < v.size(); ++i)
    {
        res += v[i] * pow(x, v.size() - 1 - i);
    }
    return res;
}
double f_prime(const vector<double> &v, double x)
{
    double res = 0;
    for (size_t i = 0; i < v.size() - 1; ++i)
    {
        res += (v.size() - 1 - i) * v[i] * pow(x, v.size() - 2 - i);
    }
    return res;
}
// Newton-Raphson method to find a root
double fun(const vector<double> &v, double x0, double tolerance)
{
    double x = x0;
    double h;

    do
    {
        h = f(v, x) / f_prime(v, x);
        x = x - h;
    } while (fabs(h) >= tolerance);

    return x; // Return the root
}

vector<double> vec(const vector<double> &v, double root)
{
    vector<double> cnt(v.size() - 1);
    double carry = 0;

    for (size_t i = 0; i < cnt.size(); ++i)
    {
        carry = v[i] + carry * root;
        cnt[i] = carry;
    }

    return cnt;
}

int main()
{
    int n;
    cout << "Enter the degree of the polynomial: ";
    cin >> n;

    vector<double> v(n + 1);
    cout << "Enter the v of the polynomial (from highest degree to constant term): ";
    for (int i = 0; i <= n; ++i)
    {
        cin >> v[i];
    }

    double x0, tolerance;
    cout << "Enter the initial guess for the first root: ";
    cin >> x0;
    cout << "Enter the error criterion (tolerance): ";
    cin >> tolerance;

    while (n > 1)
    {
        double root = fun(v, x0, tolerance);
        cout << "Root: " << fixed << setprecision(6) << root << endl;
        v = vec(v, root);
        n--;

        x0 = root;
    }
    double lastRoot = -v[1] / v[0];
    cout << "Root: " << fixed << setprecision(6) << lastRoot << endl;

    return 0;
}

// Enter the degree of the polynomial: 3
// Enter the v of the polynomial (from highest degree to constant term): 1 0 -6 4
// Enter the initial guess for the first root: 0
// Enter the error criterion (tolerance): 1e-4
// Root: 0.732051
// Root: 2.000000
// Root: -2.732051
