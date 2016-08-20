#include <bitset>
#include <iostream>

using namespace std;

void outputBinary(int);

int main() {
  int a = 5; // 101
  int b = 3; // 011

  cout << "sizeof(int) + " << sizeof(int) << endl;
  cout << "a = " << a << ", "
       << "b = " << b << endl;

  cout << "    a = ";
  outputBinary(a);
  cout << "    b = ";
  outputBinary(b);

  // 与
  cout << "a & b = ";
  outputBinary(a & b);
  // 或
  cout << "a | b = ";
  outputBinary(a | b);
  // 这个不是「按位非」，这是「逻辑非」，需要特别注意。
  cout << "   !a = ";
  outputBinary(!a);
  // 非
  cout << "   ~a = ";
  outputBinary(~a);
  // 异或
  cout << "a ^ b = ";
  outputBinary(a ^ b);
  // 左移
  cout << "a << 2 = ";
  outputBinary(a << 2);
  // 右移
  cout << "a >> 2 = ";
  outputBinary(a >> 2);

  return 0;
}

// 输出整型数的二进制形式
void outputBinary(int a) {
  std::bitset<sizeof(int) * 8> x(a);
  cout << x << endl;
}