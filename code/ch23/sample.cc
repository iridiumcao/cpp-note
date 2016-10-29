#include <iostream>

using namespace std;

class Complex {
  double real;
  double imag;

 public:
  Complex(double real = 0, double imag = 0);

  double getReal() const { return real; }
  double getImag() const { return imag; }
};

Complex::Complex(double real, double imag) {
  this->real = real;
  this->imag = imag;
}

// 本示例中没有将本函数声明为 Complex 的友元，是因为个人比较讨厌友元这个特性
ostream& operator<<(ostream& os, const Complex& c) {
  if (c.getImag() >= 0) {
    os << c.getReal() << " + " << c.getImag() << "i";
  } else {
    os << c.getReal() << " - " << -c.getImag() << "i";
  }
  return os;
}

istream& operator>>(istream& is, Complex& c) {
  string s;
  is >> s;

  bool imagFlag = true;
  int pos = s.find("+", 0);  // 作为示例演示，不考虑 +/- 前后的空格
  if (pos == -1) {
    pos = s.find("-", 0);
    imagFlag = false;
  }
  string realString = s.substr(0, pos);
  double real = atof(realString.c_str());
  string imagString = s.substr(pos + 1, s.length() - pos - 2);
  double imag = atof(imagString.c_str());
  if (!imagFlag) {
    imag = -imag;
  }

  c = Complex(real, imag);
  return is;
}

int main() {
  Complex a;
  cin >> a;
  cout << a << endl;
  Complex c(3, 4), c2(-5.6, -7.8);
  cout << c << endl << c2 << endl;
  return 0;
}

// input:
// 5-6i

// output:
// 5 - 6i
// 3 + 4i
// -5.6 - 7.8i