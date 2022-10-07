# 第24讲 自加/自减运算符的重载

> 这是运算符重载中比较特殊的例子，因为有前後++和前後--.  
> 视频地址：[https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/bHZFp/zi-zeng-zi-jian-yun-suan-fu-de-zhong-zai](https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/bHZFp/zi-zeng-zi-jian-yun-suan-fu-de-zhong-zai)

重载时，後置式比前置式多一个 `int` 型的参数，但这个参数仅用于区分前後而已，其值完全无用。这点看起来，又一次说明了运算符重载在实现上是丑陋的。

* 前置运算符作为一元运算符重载
  * 重载为成员函数
    * T & operator++\(\);
    * T & operator--\(\);
  * 重载为全局函数
    * T & operator++\(T &\);
    * T & operator--\(T &\);
* 後置运算符作为二元运算符重载，但多出的那个 `int` 型参数并无具体意义，仅仅视为了标识这是後置运算而已。
  * 重载为成员函数
    * T & operator++\(int\);
    * T & operator--\(int\);
  * 重载为全局函数
    * T & operator++\(T &, int\);
    * T & operator--\(T &, int\);

下面给丑陋的自加减运算符重载举一个例子：

```cpp

```

---

[\<Previous](ch-23-stream-insertion-operator-overloading.md) \| [Home](ch-25-inheritance.md) \| [Next\>](ch-04-reference.md)