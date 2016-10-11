class Complex {
  double real;
  double imag;

public:
  Complex(double real, double imag = 0); // 构造函数在此
};

Complex::Complex(double real, double imag) {
  this->real = real;
  this->imag = imag;
}