// 7
typedef int T;

T mod(T a, T b) {
  if (a < 0 && b >= 0) return a % b + b;
  if (a >= 0 && b < 0) return -(a % b + b);
  return a % b;
}