/*
Write a program to find the least square parabola y = a + bx + cx2 for the following data
      x         2       4      6        8
      y       1.4    2.0   2.4     2.8
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 4;
    double x[] = {2, 4, 6, 8};
    double y[] = {1.4, 2.0, 2.4, 2.8};
    double sx = 0, sx2 = 0, sx3 = 0, sx4 = 0, sy = 0, sxy = 0, sx2y = 0;

    for(int i = 0; i < n; i++) {
        double xi = x[i], yi = y[i];
        sx += xi;
        sx2 += xi * xi;
        sx3 += xi * xi * xi;
        sx4 += xi * xi * xi * xi;
        sy += yi;
        sxy += xi * yi;
        sx2y += xi * xi * yi;
    }

    double A[3][4] = {
        {n, sx, sx2, sy},
        {sx, sx2, sx3, sxy},
        {sx2, sx3, sx4, sx2y}
    };

    // Gaussian Elimination
    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 3; j++) {
            double ratio = A[j][i] / A[i][i];
            for(int k = 0; k < 4; k++) {
                A[j][k] -= ratio * A[i][k];
            }
        }
    }

    double c = A[2][3] / A[2][2];
    double b = (A[1][3] - A[1][2]*c) / A[1][1];
    double a = (A[0][3] - A[0][1]*b - A[0][2]*c) / A[0][0];

    cout << "Parabola: y = " << a << " + " << b << "x + " << c << "x^2" << endl;
    return 0;
}
