#include "CEngine.cpp"
#include "CTyre.cpp"

class CCar {
  int price;
  CTyre tyre;
  CEngine engine;

public:
  CCar(int p, int tr, int tw);
};

CCar::CCar(int p, int tr, int tw) : price(p), tyre(tr, tw) {}

int main() {
  CCar car(20000, 17, 225);
  return 0;
}