#include <iostream>
using namespace std;

class A {
public:
  void hello() { cout << "hello" << endl; }
};

int main() {
  A *p = NULL;
  p->hello();
}