#include "Complex.cpp"
#include <iostream>

int main() {
  Complex c1(3.14);                      // 自定义构造器被调用
  Complex *pc = new Complex(2.72, 3.14); // 自定义构造器被调用
  return 0;
}