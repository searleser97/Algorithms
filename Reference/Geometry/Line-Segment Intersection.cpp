// 6
#include "Data Structures/Point.cpp"

int sign(ld x) {
  if (x < 0) return -1;
  return x > 0;
}
// 12
// line: a-b, segment: u-v
// 0: no point, 1: single point, -1: infinity points
pair<int, Point> lsintersection(Point& a, Point& b,
                                Point& u, Point& v) {
  if ((b - a).cross(v - u))
    return {sign((b - a).cross(u - a)) !=
                sign((b - a).cross(v - a)),
            a + (b - a) * ((u - a).cross(v - u) /
                           (b - a).cross(v - u))};
  if ((u - a).cross(b - a)) return {0, Point()};
  return {-1, Point()};
}