int random(int min, int max) {
  return min + rand() % (max - min + 1);
}

int main() {
  srand(time(0));
  // code
}