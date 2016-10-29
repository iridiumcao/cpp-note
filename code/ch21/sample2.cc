// 重载为成员函数

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

  Complex operator+(const Complex &);  // 运算符目数只有一个
  Complex operator-(const Complex &);

  void print();
};

Complex Complex::operator+(const Complex &a) {
  return Complex(real + a.real, imaginary + a.imaginary);
}

Complex Complex::operator-(const Complex &a) {
  return Complex(real - a.real, imaginary - a.imaginary);
}

void Complex::print() {
  // 这里有个比较有趣的点： private 的成员变量可以省写 this->，但因为 this
  // 是指针，不能写成 this.real 的形式：
  // this-> real 这是合法的完整形式，
  // real 合法的简写形式，
  // this.real 非法形式，this 是指针不是引用，故也。
  if (imaginary >= 0) {
    cout << real << " + " << imaginary << "i" << endl;
  } else {
    cout << real << " - " << -imaginary << "i" << endl;
  }
}

int main() {
  Complex a(1, 2), b(3.4, 4.5), c, d;
  c = a + b;  // 相当于 c = a.operator+(b)
  c.print();
  d = a - b;
  d.print();
  return 0;
}