
#include <bits/stdc++.h>
using namespace std;

#define ll long long
void fun(string s1, string s2, int p)
{
     while (s2.size() > p)
        s2.pop_back();

    while (!s1.empty() and s1[0] == '0')
        s1.erase(s1.begin());
    if (s2.empty())
        s2 = "0";
    cout <<"Round Number:"<< s1 << '.' << s2 << endl;
}

int32_t main()
{
    int t;
    cout << "Enter the number of test case:";
    cin >> t;
    while (t--)
    {
       int i, f = 0, p;
    char ch;
    cout << "Enter the point: ";
    cin >> p;
    cout << "Enter the number: ";
    string s2 = "", s1 = "", s;
    cin >> s;
    for (auto a : s)
    {
        if (a == '.')
        {
            f = 1;
            continue;
        }
        if (f)
            s2 += a;
        else
            s1 += a;
    }

    if (s2.size() <= p)
    {
        cout <<"Round Number:"<< s1 << '.' << s2 << endl;
        return 0;
    }
     s1 = '0' + s1;

    int t = s2[p] - '0';
    int fl = 0;
    if (t < 5 or t == 5 and (s2[p - 1] - '0') % 2 == 0)
    {
        fun(s1, s2, p);
        return 0;
    }
    if (t == 5 and (s2[p - 1] - '0') % 2 or t > 5)
    {
        int ptr = p - 1;
        while (ptr >= 0)
        {
            if (s2[ptr] == '9')
            {
                s2[ptr] = '0';
                --ptr;
                fl = 1;
                continue;
            }
            else
            {
                s2[ptr] += 1;
                fl = 0;
                break;
            }
        }
         if (fl)
        {
            int ptr = s1.size() - 1;
            while (s1[ptr] == '9')
            {
                s1[ptr] = '0';
                --ptr;
            }
            ++s1[ptr];
        }
        fun(s1, s2, p);
    }
    }
}

/*
TC:
1.6583 → 1.658
30.0567 → 30.06
0.859458 → 0.8594
3.14159 → 3.142
*/
