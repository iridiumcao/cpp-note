# 第11讲 从客观世界抽象出类的例子

> 这节内容实际上是所有 OO 编程通用的内容，所有 OO 语言在使用时都有这么个抽象过程。  
> 视频地址：<https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/p0R51/cong-ke-guan-shi-wu-chou-xiang-chu-lei-de-li-zi>

从客观世界抽象出类，从过程上讲，是从具有相同或相似性质的事物个体集合中，寻找和提炼它们的共性，并利用这个共性定义它们的「类型」。形象地说就是「归纳总结」。

一类事物往往有一些属性，同时也有一些行为，比方说每个人都有他的名字，有他的性别，年龄等，那么「人」这个类型(class)可以有这些属性：
* 姓名
* 性别
* 年龄
* 身高
* ...

一个「人」他还可以执行如下动作：
* 吃饭
* 睡觉
* 打猫猫
* 计算 BMI（身高体重指数）
* ...

如此，我们可以这样定义「人」：
```
类型 人类
  属性：性别，年龄，身高，等等
  动作：吃饭，睡觉，打猫猫，算BMI，等等
```
翻译成 C++ 可以这样：
``` C++
class Human {
private:
  string name;
  double weight;
  double height;

public:
  Human(string, double, double);
  string getName() { return this->name; };
  void eat();
  void sleep();
  void daCat();

  // calculate Body Mass Index
  double calcBMI();
}; // 这里分号是必须的
... ...
```
(代码下载：[Human.cpp](code/ch11/Human.cpp), [main.cpp](code/ch11/main.cpp))

C++ 中称类的属性为「成员变量」，功能性代码块为「成员函数(member function)」，它们都是「类成员」。
这点和 Java 的称呼略有不同，Java 中称「属性」和「方法(method)」。

写代码时，具体的东西的集合会被抽象为「类型」，而反过来，通过「类型」可以构造 Object（对象，物件，实例），这一过程称为「类的实例化」。对象的大小等于所有成员变量大小之和。

对象之间可以使用 = 赋值，但不能 ==, >=, >, < 这类符号比较，除非重载这些运算符。

老师在视频中还讲到：对象的指针，对象的引用。这里不再赘述。