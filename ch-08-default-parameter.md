# 第08讲 函数缺省参数

> 相对于 Java，这是 C++ 特有的功能，对程序的扩充性有一定好处，是 C++ 灵活性的一个体现。这部分内容两个老师各讲了一次。  
> 视频地址： 1. [https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/r9ucP/han-shu-que-sheng-can-shu](https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/r9ucP/han-shu-que-sheng-can-shu) 2. [https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/sI1gG/nei-lian-cheng-yuan-han-shu-he-zhong-zai-cheng-yuan-han-shu](https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/sI1gG/nei-lian-cheng-yuan-han-shu-he-zhong-zai-cheng-yuan-han-shu)

一个函数在定义时，可以设置参数的缺省值。调用函数时，可以通过省写参数值调用这些缺省值。  
例如：

```cpp
void hello(string firstName, string lastName = "", string middleName = "");
```

调用时可以这样：

```cpp
hello("Yi", "Cao", "Zong");
hello("Yi", "Cao");
hello("Yi");
```

以上，可以省略最有边的一个或多个参数。但不可以**只**省略当中的参数，如：

```cpp
hello("Yi",,"Zong");
```

\([代码下载](https://github.com/iridiumcao/cpp-note/tree/880e117845a17eb6c60956118ca4255ee37bb412/code/ch08/ch08.cc)\)

**注意**  
调用重载函数时，可能因为有的函数设置了缺省参数引发歧义，导致编译失败：

```cpp
class Hello {
private:
  int x, y;

public:
  void init(int x = 0, int y = 0);

  // 如果要使用缺省参数就会和下一个方法混淆
  void valueX(int val = 0) { x = val; }

  int valueX() { return x; }
};

...
Hello a;
a.valueX(); //ERROR! 编译器无法判断调用哪个 valueX
```

\([代码下载](https://github.com/iridiumcao/cpp-note/tree/880e117845a17eb6c60956118ca4255ee37bb412/code/ch08/Hello.cpp)\)

---

[\<Previous](ch-07-function.md) \| [Home](SUMMARY.md) \| [Next\>](ch-09-object-oriented.md)