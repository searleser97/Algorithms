// 8
#include "Data Structures/Point.cpp"

Point projectionOnLine(Point& a, Point& b, Point& p) {
  Point pr = a + (p - a).projectOn(b - a);
  if (abs(pr.x) < eps) pr.x = 0;
  if (abs(pr.y) < eps) pr.y = 0;
  return pr;
}