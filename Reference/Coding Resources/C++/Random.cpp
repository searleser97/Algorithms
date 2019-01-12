// 3
int random(int min, int max) {
  return min + rand() % (max - min + 1);
}
// 3
int main() {
  srand(time(0));
  // code ...
}