#include <iostream>
#include <cmath>
using namespace std;

long long cps(long long N) {
    long long a = floor(sqrt(N));
    long long b = a + 1;

    long long a_square = a * a;
    long long b_square = b * b;

    if (abs(N - a_square) <= abs(N - b_square)) {
        return a_square;
    } else {
        return b_square;
    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        long long N;
        cin >> N;
        long long result = cps(N);
        cout << result << endl;
    }

    return 0;
}