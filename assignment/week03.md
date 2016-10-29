# 第03周作业 类和对象

> <https://www.coursera.org/learn/cpp-chengxu-sheji/programming/5f8jI/bian-cheng-zuo-ye-lei-he-dui-xiang>

<p style='color:red'>如果你正在 Coursera 学习这门课程，请忽略这部分内容。课程不鼓励交流作业题。</p>

## 编程题1

来源: [POJ](http://cxsjsxmooc.openjudge.cn/test/solution/7067811/) (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)  
描述  
下面程序输出的结果是：

``` C++
0
5
```

请填空：

``` C++
#include <iostream>
using namespace std;
class A {
public:
  int val;
  // 在此处补充你的代码
};
main() {
  A a;
  cout << a.val << endl;
  a.GetObj() = 5; // TODO 这是什么语法？
  cout << a.val << endl;
}
```

**输入**  
无
**输出** 

``` C++
0
5
``` 

**提示**
所缺代码具有如下形式：

``` C++
    A(_________________ ){ val = n; }
    ________________ GetObj() {
        return _________________;
    }
```

答案包含在这个文件中：[A.cpp](../code/assignment/week03/no1/A.cpp)

## 编程题2

来源: [POJ](http://cxsjsxmooc.openjudge.cn/test/3w8/)   
描述  
下面程序的输出是：
10
请补足Sample类的成员函数。不能增加成员变量。

``` C++
#include <iostream>
using namespace std;
class Sample {
public:
  int v;
  Sample(int n) : v(n) {}
  // 在此处补充你的代码
};
int main() {
  Sample a(5);
  Sample b = a;
  cout << b.v;
  return 0;
}
```

**输入**  
无   
**输出**  
10  

答案包含在这个文件中：[Sample.cpp](../code/assignment/week03/no2/Sample.cpp)

## 编程题3

来源: [POJ](http://cxsjsxmooc.openjudge.cn/test/3w9/)  
描述  
下面程序的输出结果是：

``` C++
5,5
5,5
```

请填空：

``` C++
using namespace std;
class Base {
public:
  int k;
  Base(int n) : k(n) {}
};
class Big {
public:
  int v;
  Base b;
  // 在此处补充你的代码
};
int main() {
  Big a1(5);
  Big a2 = a1;
  cout << a1.v << "," << a1.b.k << endl;
  cout << a2.v << "," << a2.b.k << endl;
  return 0;
}
```

**输入**   
无  
**输出**  

``` C++
5,5
5,5
```

**提示**
所缺代码具有如下形式：

``` C++
    Big ________________{ }
    Big ________________{ }
```

答案包含在这个文件中：[main.cpp](../code/assignment/week03/no3/main.cpp)

## 编程题4 魔兽世界之一：备战

来源: [POJ](http://cxsjsxmooc.openjudge.cn/test/B/)  
**描述**  
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。  
``红司令部，City 1，City 2，……，City n，蓝司令部``  
两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。  
双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。  
武士在刚降生的时候有一个生命值。  
在每个整点，双方的司令部中各有一个武士降生。  
红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。  
蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。  
制造武士需要生命元。  
制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。  
如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。  
给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。  

一共有两种事件，其对应的输出样例如下：  
1) 武士降生  
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter  
表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。  

2) 司令部停止制造武士  
输出样例： 010 red headquarter stops making warriors  
表示在10点整，红方司令部停止制造武士  

输出事件时：

* 首先按时间顺序输出；
* 同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

**输入**
第一行是一个整数，代表测试数据组数。  

每组测试数据共两行。

* 第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。
* 第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。

**输出**

* 对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
* 对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。
* 接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。


样例输入

``` C++
1
20
3 4 5 6 7
```

样例输出

``` C++
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
000 blue lion 1 born with strength 6,1 lion in blue headquarter
001 red lion 2 born with strength 6,1 lion in red headquarter
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
004 blue headquarter stops making warriors
```

** 分析和解答 **  
这道题目在刚刚学了这点 C++ 知识的情况下写出程序来可真是难。
因此我先用熟悉的 Java 写了一个解答，C++ 的版本正在对照修改，为了对应 Java 中的集合类，还用到了 C++ STL 等。
C++ 版本仍在修改中。  
Java 相关文件：[Headquarter.java](../code/assignment/week03/no4_java/Headquarter.java), [Warrior.java](../code/assignment/week03/no4_java/Warrior.java), [Main.java](../code/assignment/week03/no4_java/Main.java).  

附，在终端中编译 Java 代码的指令：

``` bash
$ javac -sourcepath . *.java -encoding UTF-8 -Xlint:unchecked
$ java Main
```

以上的 ``encoding`` 和 ``Xlint`` 参数不是必须的。
