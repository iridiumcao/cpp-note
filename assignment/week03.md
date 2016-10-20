# 第03周作业 类和对象

> https://www.coursera.org/learn/cpp-chengxu-sheji/programming/5f8jI/bian-cheng-zuo-ye-lei-he-dui-xiang

## 编程题1
来源: [POJ](http://cxsjsxmooc.openjudge.cn/test/solution/7067811/) (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)  
注意： 总时间限制: 1000ms 内存限制: 65536kB  
描述  
下面程序输出的结果是：
```
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
```
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
注意： 总时间限制: 1000ms 内存限制: 65536kB  
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

答案包含在这个文件中：[Sample.cpp](../code/assignment/week3/no2/Sample.cpp)

## 编程题 ＃3
来源: [POJ](http://cxsjsxmooc.openjudge.cn/test/3w9/)  

描述  

下面程序的输出结果是：
```
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
```
5,5
5,5
```
**提示**
所缺代码具有如下形式：
``` C++
    Big ________________{ }
    Big ________________{ }
```
答案包含在这个文件中：[main.cpp](../code/assignment/week3/no3/main.cpp)