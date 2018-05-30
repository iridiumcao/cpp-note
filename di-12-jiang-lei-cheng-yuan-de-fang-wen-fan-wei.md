# 第12讲 类成员的访问范围

> 类成员的访问限定关键字有：private, public, protected，前两个在 Java 中也常用。  
> 视频地址：[https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/oApWK/lei-cheng-yuan-de-ke-fang-wen-fan-wei](https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/oApWK/lei-cheng-yuan-de-ke-fang-wen-fan-wei)

类成员可被访问的范围有三：

* `private` 私有，被修饰的类成员只在成员函数内被访问。这是默认的访问权限，可以不写。
* `public` 公有，任何地方都能访问到
* `protected` 指定保护成员

三种关键字出现的次数和先后次序都无限制，例如可以将上节的 [Human.cpp](https://github.com/iridiumcao/cpp-note/tree/880e117845a17eb6c60956118ca4255ee37bb412/code/ch11/Human.cpp) 改成如下形式

```cpp
class Human {
private:
  string name;

private:
  double weight;

private:
  double height;

public:
  Human(string, double, double);

public:
  string getName() { return this->name; };

public:
  void eat();

public:
  void sleep();

public:
  void daCat();

public:
  // calculate Body Mass Index
  double calcBMI();
}; // 这里分号是必须的
```

\([代码下载](https://github.com/iridiumcao/cpp-note/tree/880e117845a17eb6c60956118ca4255ee37bb412/code/ch12/Human.cpp)\)  
这样看来，形式上还是多少有点像 Java，只是确实难看很多;\)

类的成员函数内部，可以访问：

* 当前对象的全部属性和函数
* 同类其他对象的全部属性和函数（注释1）

类的成员函数以外的地方

* 只能访问该类对象的公有成员（注释1）

注释1：需要明确指出的原因是 C++ 存在全局方法。

