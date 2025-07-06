#include <bits/stdc++.h>
using namespace std;
int main() {
    // Matrix A
    float a[3][3] = {
        {1, 1, 1},
        {1, 2, 3},
        {1, 3, 4}
    };

    // Vector B
    float b[3] = {1, 6, 6};

    // Calculate determinant of A
    float det = a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1])
              - a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0])
              + a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);

    if (det == 0) {
        cout << "Matrix is singular, no unique solution.\n";
        return 0;
    }

    // Find adjoint manually
    float adj[3][3];
    adj[0][0] =  a[1][1]*a[2][2] - a[1][2]*a[2][1];
    adj[0][1] = -(a[1][0]*a[2][2] - a[1][2]*a[2][0]);
    adj[0][2] =  a[1][0]*a[2][1] - a[1][1]*a[2][0];
    adj[1][0] = -(a[0][1]*a[2][2] - a[0][2]*a[2][1]);
    adj[1][1] =  a[0][0]*a[2][2] - a[0][2]*a[2][0];
    adj[1][2] = -(a[0][0]*a[2][1] - a[0][1]*a[2][0]);
    adj[2][0] =  a[0][1]*a[1][2] - a[0][2]*a[1][1];
    adj[2][1] = -(a[0][0]*a[1][2] - a[0][2]*a[1][0]);
    adj[2][2] =  a[0][0]*a[1][1] - a[0][1]*a[1][0];

    // Find inverse: invA = adj / det
    float inv[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            inv[i][j] = adj[i][j] / det;

    // Multiply inverse with b to get solution x
    float x[3] = {0};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            x[i] += inv[i][j] * b[j];

    // Output result
    cout << "Solution:\n";
    cout << "x = " << x[0] << endl;
    cout << "y = " << x[1] << endl;
    cout << "z = " << x[2] << endl;

    return 0;
}
