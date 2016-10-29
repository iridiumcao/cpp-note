#include <iostream>
using namespace std;

class CDemo {
  int i;

 public:
  CDemo(int i = 0);
  CDemo &operator++();          // 前置++
  CDemo operator++(int);        // 後置++
  operator int() { return n; }  // 重载()，类型

  // 用友元方式重载--
  friend CDemo &operator--(CDemo &);  // 前置--
  friend CDemo operator--(CDemo &, int);
};

CDemo::CDemo(int i) { this->i = i; }

// 前++
CDemo &CDemo::operator++() {
  i++;
  return *this;
}

// 後++
CDemo CDemo::operator++(int k) {
  CDemo tmp(*this);  // 记录修改前的对象
  i++;
  return *tmp;
}

// 前--
CDemo &operator--(CDemo &d) {
  d.n--;
  return d;
}

// 後--
CDemo operator--(CDemo &d, int k) {
  CDemo tmp(d);
  d.n--;
  return temp;
}

int main() {
  CDemo d(5);
  return 0;
}