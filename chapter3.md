# 第03讲 位运算

> 本讲内容仍然是对 C 的复习，也可以看着是面向过程的 C++.  
> 视频地址：<https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/ifzZC/wei-yun-suan>

**位运算**是对整型(char, short, int, long, etc..)变量的二进制形式进行的运算。

## 原理
程序中的位运算是基于布尔代数的规则，用``1``表示``true``, ``0``表表示``false``. 以下列出基本的运算规则。

**与 AND**，双目运算，当且仅当两数同为真时，表达式值为真。本运算在 C++ 中，还用于逻辑计算。  
**或 OR**，双目运算，当且仅当两数同为假时，表达式值为假。本运算在 C++ 中，还用于逻辑计算。  
**非 NOT**，单目运算，数的值为真时，表达式值为假，反之亦然。本运算在 C++ 中，还用于逻辑计算。  
**异或 XOR**，双目运算，两数相异得真，相同得假。本运算在 C++ 中，仅用于位运算。  
**同或 XNOR**，双目运算，两数相同得真，相异得假。本运算在 C++ 中，没有直接支持。

| A | B | A AND B | A OR B | NOT A | A XOR B | A XNOR B |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 0 | 0 | 0 | 0 | 1 | 0 | 1 |
| 0 | 1 | 0 | 1 | 1 | 1 | 0 |
| 1 | 0 | 0 | 1 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 | 0 | 1 |

C++ 进行位运算，就是把整型数转成二进制后，对应的位作以上布尔运算。  
如（注意以下代码中的位运算符号）
``` CPP
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

```
([代码下载](code/ch03/ch03.1.cpp))

编译运行后，在本机输出如下结果  
``` CPP
sizeof(int) + 4
a = 5, b = 3
    a = 00000000000000000000000000000101
    b = 00000000000000000000000000000011
a & b = 00000000000000000000000000000001
a | b = 00000000000000000000000000000111
   !a = 00000000000000000000000000000000
   ~a = 11111111111111111111111111111010
a ^ b = 00000000000000000000000000000110
a << 2 = 00000000000000000000000000010100
a >> 2 = 00000000000000000000000000000001
```
## 用途

### &, 按位与
1. 获取某数某位的值
2. 判断某数的某位是否为1
2. 将某数的某位设置为0，而其他位不变

### |, 按位或
1. 将某数的某位设置为1，而其他位不变

### ^, 按位异或
1. 将某数的某位取反，而其他位不变（自反律）
2. 交换两个整数（参「[交换两数](http://wiki.iridiumcao.info/it/algorithms/exchange-two-values)」）

附 异或的性质  
交换律：`a ^ b = b ^ a`   
结合律：`a ^ (b ^ c) = (a ^ b) ^ c`   
恒等律：`a ^ 0 = a`   
归零律：`a ^ a = 0`   
（参维基百科词条「[逻辑异或](https://zh.wikipedia.org/wiki/%E9%80%BB%E8%BE%91%E5%BC%82%E6%88%96)」，[英文版](https://en.wikipedia.org/wiki/Exclusive_or)更精彩）

推论：`a ^ b = c -> b ^ c = a, c ^ a = b`  
证明：   
`b ^ c = b ^ (a ^ b) = b ^ a ^ b = b ^ b ^ a = 0 ^ a = a`  
`c ^ a = (a ^ b) ^ a = a ^ a ^ b = 0 ^ b = b`  

### <, 左移
移动一位就相当于乘以2，移动 n 位，就相当于乘以 $$2^n$$.  

### >, 右移
移动一位就相当于除以2，移动 n 位，就相当于除以 $$2^n$$.  
原先符号位是什么，移动後就补什么。

