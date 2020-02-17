// 11
#include "Data Structures/Point.cpp"

pair<int, Point> llintersection(Point& a, Point& b,
                                Point& u, Point& v) {
  if ((b - a).cross(v - u))  // single point
    return {1, a + (b - a) * ((u - a).cross(v - u) /
                              (b - a).cross(v - u))};
  if ((b - a).cross(u - a))
    return {0, Point()};  // no points
  return {-1, Point()};   // infinity points
}