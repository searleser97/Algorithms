// 5
#include "Data Structures/Point.cpp"

ld pointLineDist(Point& a, Point& b, Point& p) {
  return ((p - a).projectOn(b - a) - (p - a)).norm();
}