#include <iostream>
using namespace std;

double dividedDifference(double x[], double y[], int n, int i, int j) {
    if (i == j) {
        return y[i];
    } else {
        return (dividedDifference(x, y, n, i + 1, j) - dividedDifference(x, y, n, i, j - 1)) / (x[j] - x[i]);
    }
}

double interpolateNewtonDD(double x[], double y[], int n, double x_interpolate) {
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = dividedDifference(x, y, n, 0, i);
        for (int j = 0; j < i; j++) {
            term *= (x_interpolate - x[j]);
        }
        result += term;
    }

    return result;
}

int main() {
    int z;

    cout << "Enter number of data: ";
    cin >> z;

    double x[z];
    double y[z];

    for (int i = 0; i < z; i++) {
        cout << "Enter the value of x[" << i << "]: ";
        cin >> x[i];
        cout << "Enter the value of y[" << i << "]: ";
        cin >> y[i];
    }

    double x_interpolate;
    cout << "Enter interpolation point: ";
    cin >> x_interpolate;

    int n = z;

    double interpolatedValue = interpolateNewtonDD(x, y, n, x_interpolate);

    cout << "Interpolated value at x = " << x_interpolate << " is: " << interpolatedValue << endl;

    return 0;
}
