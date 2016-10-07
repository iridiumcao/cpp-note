# 第05讲 常量

> 「常量」是定义後不能改变的值，是一个比较简单的概念。  
> 课程地址：[https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/cSDSy/constguan-jian-zi-he-chang-liang](https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/cSDSy/constguan-jian-zi-he-chang-liang)

C++ 中定义常量的关键字是 ``const``，例如：
``` CPP
const int LENTH = 20;
const char * CITY_NAME = "CHENGDU"; // 常量指针
```
对于常量指针，不能通过常量指针修改指向的内容，不能将常量指针赋值给非常量指针，这点和[常量引用](chapter4.md)类似。如：
``` CPP
double d = 3.2;
const double * dp = &d;
*dp = 4.2; // ERROR!
d = 4.2; // OK
```