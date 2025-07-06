#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    double x[] = {1, 2, 3, 4, 5};
    double f[] = {1, 8, 27, 64, 125};
    double a[5][5] = {0};

    // Construct the forward difference table
    for (int i = 0; i < n; i++)
    {
        a[i][0] = f[i];
    }
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            a[i][j] = a[i + 1][j - 1] - a[i][j - 1];
        }
    }

    double h = 1.0;
    double del1 = a[0][1];
    double del2 = a[0][2];
    double del3 = a[0][3];
    double del4 = a[0][4];

    // First derivative at x = 1
    double f1 = (del1 - (1.0 / 2.0) * del2 + (1.0 / 3.0) * del3 - (1.0 / 4.0) * del4) / h;

    // Second derivative at x = 1
    double f2 = (del2 - del3 + (11.0 / 12.0) * del4) / (h * h);

    cout << "First derivative at x = 1: " << f1 << endl;
    cout << "Second derivative at x = 1: " << f2 << endl;

    return 0;
}
