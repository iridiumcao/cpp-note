// 重载为友元函数

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

  Complex operator+(double real);
  friend Complex operator+(double real,
                           const Complex &c);  // 因为要用到 Complex
                                               // 对象的私有成员，所以也作为
                                               // Complex 的友元

  void print();
};

Complex Complex::operator+(double real) {
  return Complex(this->real + real, imaginary);
}

// 重载为普通函数，以满足 double + Complex 的算式
Complex operator+(double real, const Complex &c) {
  return Complex(real + c.real, c.imaginary);
}

void Complex::print() {
  if (imaginary >= 0) {
    cout << real << " + " << imaginary << "i" << endl;
  } else {
    cout << real << " - " << -imaginary << "i" << endl;
  }
}

int main() {
  Complex a(1, 2), b, c;
  b = a + 5;  // 用到的成员函数
  b.print();
  c = 5 + a;  // 用到的普通函数，并是 Complex 的友元
  c.print();
  return 0;
}