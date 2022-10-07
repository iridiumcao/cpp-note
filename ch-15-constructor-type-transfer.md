# 第15讲 类型转换构造函数

> 这是一个很鸡肋的语言特性！能不用尽量不用！  
> 本节教授的内容在前面的「[构造函数](ch-13-constructor.md)」已有应用，那里提到创建类 `CSample` 的简写形式，即使用了类型转换构造函数。  
> 视频地址：[https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/j3aOd/lei-xing-zhuan-huan-gou-zao-han-shu](https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/j3aOd/lei-xing-zhuan-huan-gou-zao-han-shu)

类型转换构造构造函数，是这样一种构造函数：1. 只有一个参数，2. 不是复制构造函数。  
它可以实现类型的自动转换，编译系统可以自动调用它去创建一个对象或变量。  
例如：

```cpp
class Complex {
public:
  double real;
  double imag;
  Complex(double real); // 这就是复制构造函数。注意参数类型，不是类的引用类型，所以它不是复制构造函数
  Complex(double real, double imag);
};

Complex::Complex(double real) {
  this->real = real;
  this->imag = 0.0;
  cout << "constructor 1 called" << endl;
}

Complex::Complex(double real, double imag) {
  this->real = real;
  this->imag = imag;
  cout << "constructor 2 called" << endl;
}

int main() {
  Complex c1(3, 4); // 调用普通构造函数2创建 c1 对象
  c1 =
      9; // 调用类型转换构造函数1创建一个临时对象，再赋值给 c1。注意这是赋值语句
  Complex c2 = 5; // 调用类型转换构造函数1创建 c2 对象。注意这不是赋值语句
  return 0;
}
```

\([代码下载](https://github.com/iridiumcao/cpp-note/tree/880e117845a17eb6c60956118ca4255ee37bb412/code/ch15/Complex.cpp)\)，输出如下：

```text
constructor 2 called
constructor 1 called
constructor 1 called
```

---

[\<Previous](ch-14-copy-constructor.md) \| [Home](SUMMARY.md) \| [Next\>](ch-16-deconstructor.md)