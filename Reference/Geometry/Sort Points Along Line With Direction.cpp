// 8
#include "Data Structures/Point.cpp"

void sortAlongLine(Point& a, Point& b,
                   vector<Point>& ps) {
  sort(ps.begin(), ps.end(), [&](Point& u, Point& v) {
    return u.dot(b - a) < v.dot(b - a);
  });
}