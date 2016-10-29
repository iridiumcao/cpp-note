// 重载为普通函数

#include <iostream>

using namespace std;

class Complex {
  double real;
  double imaginary;

 public:
  Complex(double real = 0.0, double imaginary = 0.0) {
    this->real = real;
    this->imaginary = imaginary;
  }

  void print();

  friend Complex operator+(const Complex &a, const Complex &b);
};

void Complex::print() {
  // 这里有个比较有趣的点： private 的成员变量可以省写 this->，但因为 this
  // 是指针，不能写成 this.real 的形式：
  // this-> real 这是合法的完整形式，
  // real 合法的简写形式，
  // this.real 非法形式，this 是指针不是引用，故也。
  if (imaginary >= 0) {
    cout << real << " + " << this->imaginary << "i" << endl;
  } else {
    cout << this->real << " - " << -imaginary << "i" << endl;
  }
}

Complex operator+(const Complex &a, const Complex &b) {
  return Complex(a.real + b.real, a.imaginary + b.imaginary);
}

int main() {
  Complex a(1, 2), b(2, 3), c;
  c = a + b;
  c.print();
  return 0;
}