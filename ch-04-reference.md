# 第04讲 引用

> 从 C++ 开始，C++ 和 Java 都有「引用」这个概念，但 C 没有，可以认为是变量的别名。Java 中变量类型只有两种：原生类型和引用类型。  
> 视频地址：[https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/947f4/yin-yong](https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/947f4/yin-yong)

引用的定义语法：  
普通引用：`类型名& 引用名 = 某变量名`  
常引用：`const 类型名& 引用名 = 某变量名` 函数引用：`const 引用名 = 函数名()`

几个约定：

* 定义时必须初始化为某变量。
* 只能定义为变量，不能定义为常量。
* 一旦定义为某变量的引用後，不能再定义为别的变量的引用。

常引用：

* 常引用不能对引用本身赋值，但可以对它引用的变量赋值。  
* 对象作为函数参数时，生成该参数需要调用复制构造函数，效率较低。用指针作参数，代码不够优雅。这时，可以考虑用对象的常引用做参数。

和指针定义的区别：

* 指针：例如 `int *`
* 引用：例如 `int &`  

以上比较难看的是 `*` 和 `&` 两个符号，在 C++ 中有多种含义。

---

[\<Previous](ch-03-bit-operation.md) \| [Home](SUMMARY.md) \| [Next\>](ch-05-const.md)