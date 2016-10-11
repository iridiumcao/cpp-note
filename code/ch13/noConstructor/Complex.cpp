class Complex {
  double real;
  double imag;

public:
  void set(double real, double imag);
}; // 编译器自动生成默认构造函数

void Complex::set(double real, double imag) {
  this->real = real;
  this->imag = imag;
}