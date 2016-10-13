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
6. 构造函数一般定义为``public``的，但也可以定义为``private``的，后者在使用单例模式时会用到。

## 1. 默认构造函数
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
(代码下载：[Complex.cpp](code/ch13/noConstructor/Complex.cpp), [main.cpp](code/ch13/noConstructor/main.cpp))  

这里的构造对象的方式和 Java 的语法有些不一样，需要注意，如果是 Java，只有下面这种写法：
``` Java
  Complex c1 = new Complex(); // 默认构造器被调用（Java 使用默认构造器示例）
```

## 2. 自定义构造函数
前面的 Complex 如果使用构造函数，可以改成如下形式：
``` C++
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
```
相应的调用语句如下：
``` C++
  Complex c1(3.14);                      // 自定义构造器被调用
  Complex *pc = new Complex(2.72, 3.14); // 自定义构造器被调用
```
(代码下载：[Complex.cpp](code/ch13/constructor/Complex.cpp), [main.cpp](code/ch13/constructor/main.cpp))  
注意上面定义构造器时，还使用了「[默认参数](chapter8.md)」。实际场合中，构造函数可以定义多个。

## 3. 构造函数在数组中的使用
这和 Java 的语法有很大不同，下例演示([CSample.cpp](code/ch13/array/CSample.cpp))：
``` C++
class CSample {
  int x;

public:
  CSample() { cout << "Constructor 1 called" << endl; }
  CSample(int x) {
    this->x = x;
    cout << "Constructor 2 called" << endl;
  }
}; //这个分号必不可少！

int main() {
  CSample array1[2]; // 该数组两个元素，都使用无参构造器构造

  cout << "step1" << endl;
  CSample array2[2] = {4, 5}; // 该数组两个元素，一个用4,一个用5来作为参数构造

  cout << "step2" << endl;
  CSample array3[2] = {
      4}; // 该数组两个元素，一个用4调用调用 Constructor 2，另一个调用无参构造器

  cout << "step3" << endl;
  CSample *array4 = new CSample[2]; // 该数组两个元素，都使用无参构造器构造
  delete[] array4; // TODO 为什么仅仅这里需要执行 delete，而 array1 ~ array3 并不需要？

  return 0;
}
```

输出：
```
Constructor 1 called
Constructor 1 called
step1
Constructor 2 called
Constructor 2 called
step2
Constructor 2 called
Constructor 1 called
step3
Constructor 1 called
Constructor 1 called
```
以上代码，特别需要注意的是：
``` C++
  CSample array2[2] = {4, 5}; // 该数组两个元素，一个用4,一个用5来作为参数构造
``` 
是
``` C++
  CSample array2[2] = {CSample(4), CSample(5)}; // 该数组两个元素，一个用4,一个用5来作为参数构造
``` 
的简写形式（实际上调用了[类型转换构造函数](chapter15.md)）。  
还需要注意 array4 的创建：
``` C++
  CSample *array4 = new CSample[2]; 
```
这里使用了 ``new`` 运算符，C++ 的 ``new`` 运算符返回的是指针。

下面再举一个简单例子([Hello.cpp](code/ch13/array/Hello.cpp))：
``` C++
class Hello {
public:
  Hello(int n);        // constructor 1
  Hello(int n, int m); // constructor 2
  Hello();             // constructor 3
};

Hello::Hello(int n) { cout << "Constructor 1 called" << endl; }

Hello::Hello(int n, int m) { cout << "Constructor 2 called" << endl; }

Hello::Hello() { cout << "Constructor 3 called" << endl; }

int main() {
  Hello array1[3] = {1, Hello(1, 2)};
  cout << "---------" << endl;
  Hello array2[3] = {Hello(2, 3), Hello(1, 2), 1};
  cout << "---------" << endl;
  Hello *pArray[3] = {new Hello(4), new Hello(1, 2)};
  return 0;
}
```
输出：
```
Constructor 1 called
Constructor 2 called
Constructor 3 called
---------
Constructor 2 called
Constructor 2 called
Constructor 1 called
---------
Constructor 1 called
Constructor 2 called
```
以上特别需要注意的是，*pArray 只生成了两个对象。
