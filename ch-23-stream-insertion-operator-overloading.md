# 第23讲 流插入运算符的重载

> 这个例子示范了如何对库函数的运算符进行重载。  
> 视频地址：[https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/c3tbl/liu-cha-ru-yun-suan-fu-he-liu-ti-qu-yun-suan-fu-de-zhong-zai](https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/c3tbl/liu-cha-ru-yun-suan-fu-he-liu-ti-qu-yun-suan-fu-de-zhong-zai)

| 运算符 | 原始定义 | 库函数中定义 |
| --- | --- | --- |
| `>>` | 右移运算符 | `istream` 中被定义为接受用户输入的符号 |
| `<<` | 左移运算符 | `ostream` 中被定义为输出符号 |

用于位运算的左右移运算符在 `iostream` 中已经被被重载为输入输出的函数。 我们不能修改已有的标准库，只能将 `<<` 重载为**全局函数**，第一个参数及返回值的类型都是 `ostream &`，也可以将 `>>` 重载为全局函数，第一个参数及返回值的类型都是 `isteam &`.  
下面是完整的代码：

```cpp
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
```

输入：

```text
5-6i
```

输出：

```text
5 - 6i
3 + 4i
-5.6 - 7.8i
```

\([代码下载](https://github.com/iridiumcao/cpp-note/tree/880e117845a17eb6c60956118ca4255ee37bb412/code/ch23/sample.cc)\)

---

[\<Previous](ch-22-int-array.md) \| [Home](SUMMARY.md) \| [Next\>](ch-24-operator-overloading-self-add-minus.md)