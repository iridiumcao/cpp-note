# 第16讲 析构函数(Destructor)

> 这是 Java 没有的语言特性，也是 C++ 相对比较麻烦的一个语言特性。  
> 视频地址：<https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/L5MtC/xi-gou-han-shu>

析构函数在对象消亡前做善后工作。它在对象消亡时会被**自动**调用，用于释放对象占用的空间等。

析构函数也是一种成员函数，它：
1. 名字和类名相同
2. 名字前有 ``~`` 符号
3. 无参数和返回值
4. 一个类**最多只有一个**析构函数

定义类时如果没有自定义析构函数，则编译器会生成默认的析构函数，但默认的析构函数不涉及释放用户申请的内存释放等清理工作。
所以说如果程序中手动申请过对象，就需要自定义析构函数了，在自定义的析构函数了显示调用 ``delete`` 语句。
如果自定义了析构函数，则编译器不会使用默认的析构函数。
下面的例子展示了在析构函数中清理创建对象时用 ``new`` 分配的内存空间。
``` C++
class String {
  char *p;

public:
  String() { p = new char[10]; }
  ~String();
};

String::~String() { delete[] p; }
```
([代码下载](code/ch16/String.cpp))  

对象数组生命周期结束时，对象数组的每个元素的析构函数都会被调用，参下面的例子：

``` C++
class CTest {
public:
  ~CTest() { cout << "destructor called" << endl; }
};

int main() {
  CTest array[3];
  cout << "End main" << endl;
  return 0;
}
```
([代码下载](code/ch16/CTest.cpp))  
将输出：
```
End main
destructor called
destructor called
destructor called
```

一个比较复杂的示例：
``` C++
class Demo {
  int id;

public:
  Demo(int id) {
    this->id = id;
    cout << "id = " << id << ", Constructed" << endl;
  }
  ~Demo() { cout << "id = " << id << ", Destructed" << endl; }
};

///////////////

Demo d1(1);

void func() {
  static Demo d2(2);
  Demo d3(3);
  cout << "func" << endl;
}

int main() {
  Demo d4(4);
  d4 = 6;
  cout << "main" << endl;
  { Demo d5(5); }
  func();
  cout << "main ends" << endl;
  return 0;
}
```
([代码下载](code/ch16/Demo.cpp))，输出结果为：
```
id = 1, Constructed
id = 4, Constructed
id = 6, Constructed
id = 6, Destructed
main
id = 5, Constructed
id = 5, Destructed
id = 2, Constructed
id = 3, Constructed
func
id = 3, Destructed
main ends
id = 6, Destructed
id = 2, Destructed
id = 1, Destructed
```
分析如下：
``` C++
Demo d1(1); // 首先调用，输出 "id = 1, Constructed"

void func() {
  static Demo d2(2); // 静态对象，在程序结束时才消亡
  Demo d3(3); // 普通对象，在函数调用结束时消亡
  cout << "func" << endl;
}

int main() {
  Demo d4(4); // 输出 "id = 4, Constructed"
  // 调用类型转化构造函数，生成临时对象，并把值赋给 d4，然后消亡，即构造 id 为6的对象，然后消亡。
  // 这里 d4 的 id 被修改为 6，故程序结束时，d4 消亡时，输出的是 "id = 6, Destructed"
  d4 = 6; 
  cout << "main" << endl;
  { Demo d5(5); } // 在花括号中生成的对象，生命周期业局限于花括号内
  func();
  cout << "main ends" << endl;
  return 0;
}
```
同一个生命周期内，对象的创建顺序和它们的消亡顺序是相反的。

---
一点说明  
1. 个别调用情况可能和上面说明的不一致，是因为：
  * 编译器有 bug
  * 代码优化措施
2. 前面讨论的是 C++ 标准