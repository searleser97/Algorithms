// 6
#include "Data Structures/Point.cpp"

bool isPointInSegment(Point& a, Point& b, Point& p) {
  return !(b - a).cross(p - a) &&
         (a - p).dot(b - p) <= 0;
}