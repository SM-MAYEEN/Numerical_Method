/*
Write a program to find the least square line y = a + bx for the following data
        x     -2    -1     0     1     2
        y     1     2      3      4     5
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i =0;
    cout<<"Enter number of entries: ";
    cin>>n;
    vector<double>x(n),y(n);
    double sum_x = 0, sum_y= 0, sum_x2 = 0,sum_xy=0;
    cout<<"Enter "<<n<<" entries of x: ";
    for(auto &a : x)
    {
        cin>>a;
        sum_x +=a;
        sum_x2 += (a*a);
    }
    cout<<"Enter "<<n<<" entries of y: ";
    for(auto &a : y)
    {
        cin>>a;
        sum_y += a;
        sum_xy += (x[i++] * a);
    }

    double b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double a = (sum_y - b * sum_x) / n;

    cout<<"a value is:"<<a<<endl;
    cout<<"b value is:"<<b<<endl;

    cout << "Line Equation: y = " << a << " + " << b << "x" << endl;
    return 0;
}
/*
Input:
5
-2 -1 0 1 2
1 2 3 4 5
Output:
a=3
b=1
The line equation is : y = 3+1x
*/
