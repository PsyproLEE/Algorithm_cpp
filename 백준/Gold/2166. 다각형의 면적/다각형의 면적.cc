#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    long long sum1 = 0; // x_i * y_{i+1} 합
    long long sum2 = 0; // y_i * x_{i+1} 합

    for (int i = 0; i < n; ++i) {
        int next = (i + 1) % n;
        sum1 += points[i].x * points[next].y;
        sum2 += points[i].y * points[next].x;
    }

    double area = abs(sum1 - sum2) / 2.0;

    cout << fixed << setprecision(1) << area << endl;

    return 0;
}