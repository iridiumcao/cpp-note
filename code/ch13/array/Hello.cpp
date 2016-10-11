#include <iostream>
using namespace std;

class Hello {
public:
  Hello(int n);        // constructor 1
  Hello(int n, int m); // constructor 2
  Hello();             // constructor 3
};

Hello::Hello(int n) { cout << "Constructor 1 called" << endl; }

Hello::Hello(int n, int m) { cout << "Constructor 2 called" << endl; }

Hello::Hello() { cout << "Constructor 3 called" << endl; }

int main() {
  Hello array1[3] = {1, Hello(1, 2)};
  cout << "---------" << endl;
  Hello array2[3] = {Hello(2, 3), Hello(1, 2), 1};
  cout << "---------" << endl;
  Hello *pArray[3] = {new Hello(4), new Hello(1, 2)};
  return 0;
}