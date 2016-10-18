#include <iostream>
using namespace std;

class Demo {
  int id;

public:
  Demo(int id) {
    this->id = id;
    cout << "id = " << id << ", Constructed" << endl;
  }
  ~Demo() { cout << "id = " << id << ", Destructed" << endl; }
};

///////////////

Demo d1(1);

void func() {
  static Demo d2(2);
  Demo d3(3);
  cout << "func" << endl;
}

int main() {
  Demo d4(4);
  d4 = 6;
  cout << "main" << endl;
  { Demo d5(5); }
  func();
  cout << "main ends" << endl;
  return 0;
}
// 输出结果如下:
// id = 1, Constructed
// id = 4, Constructed
// id = 6, Constructed
// id = 6, Destructed
// main
// id = 5, Constructed
// id = 5, Destructed
// id = 2, Constructed
// id = 3, Constructed
// func
// id = 3, Destructed
// main ends
// id = 6, Destructed
// id = 2, Destructed
// id = 1, Destructed
