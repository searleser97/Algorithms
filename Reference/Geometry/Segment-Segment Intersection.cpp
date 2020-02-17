// 6
#include "Data Structures/Point.cpp"

int sign(ld x) {
  if (x < 0) return -1;
  return x > 0;
}
// 3
void swap(Point& a, Point& b) {
  swap(a.x, b.x), swap(a.y, b.y);
}
// 17
// 0: no point, 1: single point, -1: infinity points
pair<int, Point> ssintersection(Point a, Point b,
                                Point u, Point v) {
  if ((b - a).cross(v - u))
    return {sign((b - a).cross(u - a)) !=
                    sign((b - a).cross(v - a)) &&
                sign((v - u).cross(a - u)) !=
                    sign((v - u).cross(b - u)),
            a + (b - a) * ((u - a).cross(v - u) /
                           (b - a).cross(v - u))};
  if ((b - a).cross(u - a)) return {0, Point()};
  if (a > b) swap(a, b);
  if (u > v) swap(u, v);
  if (a > u) swap(a, u), swap(b, v);
  if (u < b) return {-1, Point()};
  return {b == u, u};
}