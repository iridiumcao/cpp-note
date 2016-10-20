# 第05讲 常量

> 「常量」是定义後不能改变的值，是一个比较简单的概念。  
> 视频地址：
> * <https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/cSDSy/constguan-jian-zi-he-chang-liang>
> * <https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/wrcJr/chang-liang-dui-xiang-chang-liang-cheng-yuan-han-shu-he-chang-yin-yong>

常量即恒常的量，不可修改（重新赋值），在 C++ 中用 ``const`` 关键字标识，例如：
``` CPP
const int LENTH = 20;
const char * CITY_NAME = "CHENGDU"; // 常量指针
```
对于**常量指针**，不能通过常量指针修改指向的内容，不能将常量指针赋值给非常量指针，这点和[常量引用](chapter4.md)类似。如：
``` CPP
double d = 3.2;
const double * dp = &d;
*dp = 4.2; // ERROR!
d = 4.2; // OK
```

**常量对象**，**常量成员函数**：  
常量成员函数中不能修改非静态成员变量的值，亦不能调用非静态成员函数。常量对象只能调用常量成员函数。  
两个成员函数，名字和参数表相同，返回值也相同，但一个是 ``const``，另一个不是，这两个函数算重载。常量成员函数归常量对象调用，非常量成员函数归普通对象调用。

## 问题
1. C++ 的 ``const`` 对象和 Java 的 ``final`` 对象联系？