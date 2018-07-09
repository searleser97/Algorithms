#include <bits/stdc++.h>

using namespace std;

struct Hola {
  int x = 0, y = 0;
};

// int &id = i; just keeps the first initialization

int main() {
  
  Hola *h = new Hola();
  Hola *h1 = new Hola();
  Hola *hh = h;
  h->x = 1;
  h->y = 2;
  hh = h1;
  hh->x = 5;

  cout << h1->x << endl;
  return 0;
}