// 8
#include "Data Structures/Point.cpp"

Point reflectionOnLine(Point& a, Point& b, Point& p) {
  Point r = a * 2 + (p - a).projectOn(b - a) * 2 - p;
  if (abs(r.x) < eps) r.x = 0;
  if (abs(r.y) < eps) r.y = 0;
  return r;
}