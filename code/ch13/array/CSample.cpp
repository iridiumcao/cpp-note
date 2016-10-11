#include <iostream>

using namespace std;

class CSample {
  int x;

public:
  CSample() { cout << "Constructor 1 called" << endl; }
  CSample(int x) {
    this->x = x;
    cout << "Constructor 2 called" << endl;
  }
}; //这个分号必不可少！

int main() {
  CSample array1[2]; // 该数组两个元素，都使用无参构造器构造

  cout << "step1" << endl;
  CSample array2[2] = {4, 5}; // 该数组两个元素，一个用4,一个用5来作为参数构造

  cout << "step2" << endl;
  CSample array3[2] = {
      4}; // 该数组两个元素，一个用4调用调用 Constructor 2，另一个调用无参构造器

  cout << "step3" << endl;
  CSample *array4 = new CSample[2]; // 该数组两个元素，都使用无参构造器构造
  delete[] array4;

  return 0;
}