/*
Write a program to find the best possible values of a and b from the relation y = aebx for the following data:
    x	2	10	26	61
    y	600	500	400	350

*/
/*
ln(y) = ln(a) + bx
Y = a+ bX.

*/
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cout<<"Enter number of entries: ";
    cin>>n;
    double sum_x = 0, sum_y = 0, sum_x2 = 0,sum_xy = 0;
    vector<double> x(n + 1), y (n + 1);
    cout<<"Enter the "<<n<<" entries of x:";
    for( int i = 1; i <= n; i++)
    {
        cin>>x[i];
        sum_x += x[i];
        sum_x2 += (x[i] * x[i]);
    }

    cout<<"Enter the "<<n<<" entries of y:";
    for( int i = 1; i <= n; i++)
    {
        cin>>y[i];
        y[i] = log(y[i]);
        sum_y += y[i];
        sum_xy += x[i] * y[i];
    }
    double b = (n * (sum_xy)) - (sum_x * sum_y);
    b /= (1.00 * n * sum_x2) - (1.00 * sum_x * sum_x);
    sum_x /= (1.00 * n);
    sum_y /= (1.00 * n);
    double a = sum_y - (b* sum_x);
    a = exp(a);
    cout<<"y = "<<a<<"e^"<<b<<"x\n";
}

/*
Input:
5
2 10 26	61
600 500	400	350
output:
y = 558.191e^-0.00846335x
Input:
5
1 3 5 7 9
2.473 6.722 18.274 49.673 135.026
Output:
y = 1.49992e^0.500007x
*/
