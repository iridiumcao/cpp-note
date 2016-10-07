# 第07讲 内联函数、函数重载

> 相对于 Java，「内联函数」是 C++ 特有的概念。  
> 视频地址：[https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/ieH1V/nei-lian-han-shu-he-zhong-zai-han-shu](https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/ieH1V/nei-lian-han-shu-he-zhong-zai-han-shu)

## 内联函数
函数调用会产生额外的开销：传参数入栈，计算後的结果从栈中取出。如果一个函数本身很小，或被调用次数较多，可能在效率上不够经济，就通过「内联」的方式把函数的内容复制到调用的位置。  
例如：
``` CPP 
inline int max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}
```
``inline`` 是标识内联函数的关键字。  
在当前的大内存情况下，一般应用程序，应该是不需要太考虑这个问题的，这也可见 C++ 诞生的计算机性能情况。

## 重载函数
这个概念在 Java 中也用的很多，即 overload. 函数名相同，参数个数或参数类型不同的函数称为「重载」。  
需要注意的是，在同一个类中，只是返回类型不同但参数个数和类型相同的情况，无论在 Java 还是 C++ 中都是不支持的。C 语言中不能定义两个函数名相同的函数。
如果有以下两个函数：
``` CPP
int max(int x, int y); // function a
double max(double x, double y); // function b
```
则以下语句的调用情况如列：
``` CPP
max(3, 4); // invoke function a
max(2.5, 3.2); // invoke function b
max(2, 3.4); // compile ERROR!
```
（[代码下载](code/ch07/ch07_overload.cc))
