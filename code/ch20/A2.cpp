#include <iostream>
using namespace std;

class A2 {
  int i;

public:
  void hello() { cout << i << ", hello" << endl; }
};

int main() {
  A2 *p = NULL;
  p->hello();
}