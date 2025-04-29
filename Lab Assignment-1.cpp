
#include<bits/stdc++.h>
using namespace std;

int fun(double n) {
     if (n == 0) return 0;   
     string s =  to_string(n);
    
     if (s.find('.') !=  string::npos) {
        s.erase(s.find_last_not_of('0') + 1,string::npos);
    }

     size_t a = s.find_first_not_of("0");
    if (a != std::string::npos) {
        s = s.substr(a);
    }

    int cnt = 0;
    bool f = false;

    for (char c : s) {
        if (c == '.') {
            f = true;  
            continue;  
        }
        if (c != '0') {
            cnt++;  
        } else if (f) {
            cnt++;  
        }
    }

    return cnt;
}

int main() {
    double n;
     cout << "Enter a number: ";
    cin >> n;

    int ans = fun(n);
    cout << "The number of significant digits is: " << ans << endl;

    return 0;
}
