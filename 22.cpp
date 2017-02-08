
#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

int main() {

    const int N = 20;
    int n;
    do {
        cout << "n = ";
        cin >> n;
    } while (n < 3 || n > N);

    Point a[N];
    for (int i = 0; i < n; ++i) {
        cout << "Point " << i + 1 << ": ";
        cin >> a[i].x >> a[i].y;
    }

    const double EPS = 1e-10;

    for (int i = n - 1; i >= 0; --i)
        for (int j = 0; j < i; ++j)
            if ((a[j].x > a[j + 1].x) ||
                (fabs(a[j].x - a[j + 1].x) < EPS && a[j].y > a[j + 1].y)) {
                Point temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }

    int first = 0;
    while (fabs(a[0].x - a[++first].x) < EPS);

    Point begin = a[first - 1];
    for (int i = n - 1; i >= 0; --i)
        for (int j = first; j < i; ++j) {
            double k1 = (begin.y - a[j].y) / (begin.x - a[j].x);
            double k2 = (begin.y - a[j + 1].y) / (begin.x - a[j + 1].x);
            if ((-k1 > -k2) || (fabs(k1 - k2) < EPS && a[j].x > a[j + 1].x)) {
                Point temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }

    for (int i = 0; i < n; ++i)
        cout << "Point " << i + 1 << ": " << a[i].x << ' ' << a[i].y << endl;
}