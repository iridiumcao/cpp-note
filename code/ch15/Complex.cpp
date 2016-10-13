#include <iostream>

using namespace std;

class Complex {
public:
  double real;
  double imag;
  Complex(double real); // 这就是复制构造函数
  Complex(double real, double imag);
};

Complex::Complex(double real) {
  this->real = real;
  this->imag = 0.0;
  cout << "constructor 1 called" << endl;
}

Complex::Complex(double real, double imag) {
  this->real = real;
  this->imag = imag;
  cout << "constructor 2 called" << endl;
}

int main() {
  Complex c1(3, 4); // 调用普通构造函数2创建 c1 对象
  c1 =
      9; // 调用类型转换构造函数1创建一个临时对象，再赋值给 c1。注意这是赋值语句
  Complex c2 = 5; // 调用类型转换构造函数1创建 c2 对象。注意这不是赋值语句
  return 0;
}