// 7
#include "Count Set Bits.cpp"
#include "Is Even.cpp"
bool parityCheck(int n) {
  return !__builtin_parity(n);
  // return !__builtin_parityl(n); for long
  // return !__builtin_parityll(n); for long long
}
// 3
bool parityCheck(int n) {
  return isEven(popCount(n));
}