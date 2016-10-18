#include <iostream>
using namespace std;

class CTest {
public:
  ~CTest() { cout << "destructor called" << endl; }
};

int main() {
  CTest array[3];
  cout << "End main" << endl;
  return 0;
}