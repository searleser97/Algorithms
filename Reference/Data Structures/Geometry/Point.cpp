// 7
typedef long double ld;
const ld pi = acos(-1);

struct Point {
  ld x, y;
  Point() : x(0), y(0) {}
  Point(ld x, ld y) : x(x), y(y) {}
  // 3
  Point operator+(const Point &p) {
    return Point(x + p.x, y + p.y);
  }
  // 3
  Point operator-(const Point &p) {
    return Point(x - p.x, y - p.y);
  }
  // 3
  Point operator*(const ld &k) {
    return Point(x * k, y * k);
  }
  // 3
  Point operator/(const ld &k) {
    return Point(x / k, y / k);
  }
  // 3
  ld dot(const Point &p) {
    return x * p.x + y * p.y;
  }
  // 3
  ld cross(const Point &p) {
    return x * p.y - y * p.x;
  }
  // 3
  ld norm() const { return sqrt(x * x + y * y); }
  Point perpendicularLeft() { return Point(-y, x); }
  Point perpendicularRight() { return Point(y, -x); }
  // 6
  Point rotate(ld deg) {
    ld rad = (deg * pi) / 180.0;
    return Point(x * cos(rad) - y * sin(rad),
                 x * sin(rad) + y * cos(rad));
  }
};