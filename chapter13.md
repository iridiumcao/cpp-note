# 第13讲 构造函数

>
> 视频地址：<https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/8lhFP/gou-zao-han-shu>

构造函数，也称「构造器」，顾名思义即用于构造对象的函数。
1. 构造函数只用与构造对象。对象生成时会调用构造函数，但对象一旦生成，并不能在其上执行构造函数。这也是构造函数和普通成员函数的区别。
2. 构造函数没有返回值，void 类型也不行。
3. 构造函数的名称和类名相同
4. 一个类可以多个构造函数
5. 如果不定义构造函数，编译器会自动生成默认的无参构造函数。如果自定义了构造函数，则将不会生成默认构造函数。
    * 默认构造函数无参数，不做任何操作。

构造函数执行必要的初始化操作，相当于 init 函数。功能上讲，如果不定义构造函数，仅使用默认的无参构造函数，就需要定义初始化函数，对象的创建和初始化分两步走，这比只定义和使用一次构造函数要复杂，更容易引入 bug.
以下是一个调用默认构造器的例子：
``` C++
class Complex {
  double real;
  double imag;

public:
  void set(double real, double imag);
}; // 编译器自动生成默认构造函数
```
可以通过下面两种方式使用默认构造器：
``` C++
  Complex c1;                // 默认构造器被调用
  Complex *pc = new Complex; // 默认构造器被调用
```
(代码下载：[Human.cpp](code/ch13/Complex.cpp), [main.cpp](code/ch13/main.cpp))  
这里的构造对象的方式和 Java
