/*문제 : https://www.acmicpc.net/problem/11664
  알고리즘 : 수학, 기하학, 3차원 기하학, 삼분 탐색
  티어 : Gold5
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point {
    double x, y, z;
};

inline double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

int main() {
    Point a, b, c;
    cin >> a.x >> a.y >> a.z;
    cin >> b.x >> b.y >> b.z;
    cin >> c.x >> c.y >> c.z;

    double dx = b.x - a.x;
    double dy = b.y - a.y;
    double dz = b.z - a.z;

    double low = 0, high = 1;
    while ((high - low) >= 1e-12) {
        double m1 = (2 * low + high) / 3;
        double m2 = (low + 2 * high) / 3;

        Point mid1 = {a.x + dx * m1, a.y + dy * m1, a.z + dz * m1};
        Point mid2 = {a.x + dx * m2, a.y + dy * m2, a.z + dz * m2};

        double d1 = dist(mid1, c);
        double d2 = dist(mid2, c);

        if (d1 > d2) {
            low = m1;
        } else {
            high = m2;
        }
    }

    double m = (low + high) / 2;
    Point mid = {a.x + dx * m, a.y + dy * m, a.z + dz * m};
    cout.precision(10);
    cout << fixed << dist(mid, c) << endl;
}
