// 5
#include "Data Structures/Point.cpp"

bool isPointInLine(Point& a, Point& b, Point& p) {
  return !(b - a).cross(p - a);
}