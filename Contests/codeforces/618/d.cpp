#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define forr(_, x, n) for (int _ = x; ~_; _--)
#define fos(_, x, n, s) for (int _ = x; _ < n; _ += s)
#define forn(_, x, n) fos(_, x, n, 1)
#define rep(_, n) forn(_, 0, n)
#define fi first
#define se second
#define pb push_back
#define pairii pair<int, int>
#define cerr(s) cerr << "\033[48;5;196m\033[38;5;15m" << s << "\033[0m"
// typedef __int128_t lli;
typedef long long int li;
typedef long double ld;

const ld eps = 1e-9;

bool eq(ld a, ld b) { return abs(a - b) <= eps; }
bool neq(ld a, ld b) { return abs(a - b) > eps; }
bool gr(ld a, ld b) { return a - b > eps; }
bool le(ld a, ld b) { return b - a > eps; }
bool geq(ld a, ld b) { return a - b >= -eps; }
bool leq(ld a, ld b) { return b - a >= -eps; }
const ld pi = acos(-1), inf = 1 << 30;
// (PointB - PointA) = vector from A to B.
struct Point {
  ld x, y;
  Point() : x(0), y(0) {}
  Point(ld x, ld y) : x(x), y(y) {}
  
  Point operator+(const Point &p) const {
    return Point(x + p.x, y + p.y);
  }
  
  Point operator-(const Point &p) const {
    return Point(x - p.x, y - p.y);
  }
  
  Point operator*(const ld &k) const {
    return Point(x * k, y * k);
  }
  
  Point operator/(const ld &k) const {
    return Point(x / k, y / k);
  }
  
  bool operator==(const Point &p) const {
    return eq(x, p.x) && eq(y, p.y);
  }
  
  bool operator!=(const Point &p) const {
    return !(*this == p);
  }
  
  bool operator<(const Point &p) const {
    return eq(x, p.x) ? le(y, p.y) : le(x, p.x);
  }
  
  bool operator>(const Point &p) const {
    return eq(x, p.x) ? gr(y, p.y) : gr(x, p.x);
  }

  ld norm() const { return sqrt(x * x + y * y); }

  ld dot(const Point &p) { return x * p.x + y * p.y; }
  
  ld cross(const Point &p) {
    return x * p.y - y * p.x;
  }

  Point perpendicularLeft() { return Point(-y, x); }

  Point perpendicularRight() { return Point(y, -x); }
  
  Point rotate(ld deg) {
    ld rad = (deg * pi) / 180.0;
    return Point(x * cos(rad) - y * sin(rad),
                 x * sin(rad) + y * cos(rad));
  }

  Point unit() const { return (*this) / norm(); }
  
  Point projectOn(const Point &p) {
    return p.unit() * (dot(p) / p.norm());
  }
  
  ld angleWith(const Point &p) {
    ld x = dot(p) / norm() / p.norm();
    return acos(max(-1.0L, min(1.0L, x)));
  }
  
  bool isPerpendicularWith(const Point &p) {
    return dot(p);
  }

  // ans > 0 p is on the left
  // ans < 0 p is on the right
  // ans == 0 p has our same direction
  ld positionOf(const Point &p) { return cross(p); }
};

istream &operator>>(istream &is, Point &p) {
  return is >> p.x >> p.y;
}

ostream &operator<<(ostream &os, const Point &p) {
  return os << "(" << p.x << ", " << p.y << ")";
}

void _main(int tc) {
  int n;
  cin >> n;
  if (n & 1) {
    cout << "NO" << endl;
    return;
  }
  vector<Point> v(n);
  rep(i, n) {
    cin >> v[i];
  }
  vector<Point> edges(n);
  rep(i, n) {
    edges[i] = v[(i + 1) % n] - v[i];
  }

  rep(i, n / 2 - 1) {
    if (edges[i].norm() != edges[n / 2 + i].norm() || edges[i].cross(edges[n / 2 + i])) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  _main(0);
  return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
} 
