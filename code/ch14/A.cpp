#include <iostream>

using namespace std;

class A {
public:
  A(){}; // 这里这个无参构造函数也必须写上，否则 A a 不能正常生成对象
  A(A &a);
};

A::A(A &a) {
  //仅演示用，这里没有什么复制功能
  cout << "Copy constructor called." << endl;
}

//空函数
void func(A a) { // 参数类型是 A.
}

int main() {
  A a;
  func(a); // 输出 "Copy constructor called."
  return 0;
}