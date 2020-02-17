// 9
typedef long double ld;
const ld eps = 1e-9;

bool eq(ld a, ld b) { return abs(a - b) <= eps; }
bool neq(ld a, ld b) { return abs(a - b) > eps; }
bool gr(ld a, ld b) { return a - b > eps; }
bool le(ld a, ld b) { return b - a > eps; }
bool geq(ld a, ld b) { return a - b >= -eps; }
bool leq(ld a, ld b) { return b - a >= -eps; }