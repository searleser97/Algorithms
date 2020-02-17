// 9
#include "../../Coding Resources/C++/Double Comparisons With Given Precision.cpp"

const ld pi = acos(-1), inf = 1 << 30;
// (PointB - PointA) = vector from A to B.
struct Point {
  ld x, y;
  Point() : x(0), y(0) {}
  Point(ld x, ld y) : x(x), y(y) {}
  // 3
  Point operator+(const Point &p) const {
    return Point(x + p.x, y + p.y);
  }
  // 3
  Point operator-(const Point &p) const {
    return Point(x - p.x, y - p.y);
  }
  // 3
  Point operator*(const ld &k) const {
    return Point(x * k, y * k);
  }
  // 3
  Point operator/(const ld &k) const {
    return Point(x / k, y / k);
  }
  // 3
  bool operator==(const Point &p) const {
    return eq(x, p.x) && eq(y, p.y);
  }
  // 3
  bool operator!=(const Point &p) const {
    return !(*this == p);
  }
  // 3
  bool operator<(const Point &p) const {
    return eq(x, p.x) ? le(y, p.y) : le(x, p.x);
  }
  // 3
  bool operator>(const Point &p) const {
    return eq(x, p.x) ? gr(y, p.y) : gr(x, p.x);
  }

  ld norm() const { return sqrt(x * x + y * y); }

  ld dot(const Point &p) { return x * p.x + y * p.y; }
  // 3
  ld cross(const Point &p) {
    return x * p.y - y * p.x;
  }

  Point perpendicularLeft() { return Point(-y, x); }

  Point perpendicularRight() { return Point(y, -x); }
  // 5
  Point rotate(ld deg) {
    ld rad = (deg * pi) / 180.0;
    return Point(x * cos(rad) - y * sin(rad),
                 x * sin(rad) + y * cos(rad));
  }

  Point unit() const { return (*this) / norm(); }
  // 3
  Point projectOn(const Point &p) {
    return p.unit() * (dot(p) / p.norm());
  }
  // 4
  ld angleWith(const Point &p) {
    ld x = dot(p) / norm() / p.norm();
    return acos(max(-1.0L, min(1.0L, x)));
  }
  // 4
  bool isPerpendicularWith(const Point &p) {
    return dot(p);
  }
  // 5
  // ans > 0 p is on the left
  // ans < 0 p is on the right
  // ans == 0 p has our same direction
  ld positionOf(const Point &p) { return cross(p); }
};
// 3
istream &operator>>(istream &is, Point &p) {
  return is >> p.x >> p.y;
}
// 3
ostream &operator<<(ostream &os, const Point &p) {
  return os << "(" << p.x << ", " << p.y << ")";
}