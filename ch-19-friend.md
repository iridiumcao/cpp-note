# 第19讲 友元

> 这是一个应该尽量避免使用的鸡肋语言特性，学习它的意义只是为了能看懂老旧代码。Java 中没相同或相类的语言特性。  
> 本笔记也不多记录这个特性。  
> 视频地址：[https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/T0JfZ/you-yuan](https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/T0JfZ/you-yuan)

友元破坏了对象的封装性，应当避免使用。

友元函数

* 一个类的友元函数可以访问该类的私有变量

友元类

* A是B的友元类：A的成员函数可以访问B的私有成员。
* 友元类之间的关系不能传递，不能继承。

---

[\<Previous](ch-18-member-object-and-enclosed-class.md) \| [Home](SUMMARY.md) \| [Next\>](ch-20-pointer-this.md)