#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;
};

long long ccw(Point p1, Point p2, Point p3) {
    long long result = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    if (result > 0) return 1;
    if (result < 0) return -1;
    return 0;
}

bool is_on_segment(Point p1, Point p2, Point p3) {
    return (min(p1.x, p2.x) <= p3.x && p3.x <= max(p1.x, p2.x) &&
            min(p1.y, p2.y) <= p3.y && p3.y <= max(p1.y, p2.y));
}

bool is_intersect(Point p1, Point p2, Point p3, Point p4) {
    long long ccw123 = ccw(p1, p2, p3);
    long long ccw124 = ccw(p1, p2, p4);
    long long ccw341 = ccw(p3, p4, p1);
    long long ccw342 = ccw(p3, p4, p2);

    if (ccw123 * ccw124 < 0 && ccw341 * ccw342 < 0) {
        return true;
    }

    if (ccw123 == 0 && is_on_segment(p1, p2, p3)) {
        return true;
    }
    if (ccw124 == 0 && is_on_segment(p1, p2, p4)) {
        return true;
    }
    if (ccw341 == 0 && is_on_segment(p3, p4, p1)) {
        return true;
    }
    if (ccw342 == 0 && is_on_segment(p3, p4, p2)) {
        return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cin >> p3.x >> p3.y >> p4.x >> p4.y;

    if (p1.x > p2.x || (p1.x == p2.x && p1.y > p2.y)) {
        swap(p1, p2);
    }
    if (p3.x > p4.x || (p3.x == p4.x && p3.y > p4.y)) {
        swap(p3, p4);
    }

    if (is_intersect(p1, p2, p3, p4)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}