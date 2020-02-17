// 6
#include "Data Structures/Point.cpp"
// ans > 0 p is on the left of a-b
// ans < 0 p is on the right of a-b
ld pointLineDist(Point& a, Point& b, Point& p) {
  return (b - a).cross(p - a) / (b - a).norm();
}