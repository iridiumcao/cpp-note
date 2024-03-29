# 第17讲 静态成员变量和静态成员函数

> 静态成员即所谓「类成员」，在成员前添加 `static` 修饰。这个概念在 Java 中也是一致的。  
> 视频地址：[https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/XEgIH/jing-tai-cheng-yuan-bian-liang-he-jing-tai-cheng-yuan-han-shu](https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/XEgIH/jing-tai-cheng-yuan-bian-liang-he-jing-tai-cheng-yuan-han-shu)  
> 视频中举出的应用案例：计算同一个类的图形总数和总面积，在实际开发中，应尽量避免这种用法，视频最后也提到了通过自定义复制构造函数解决问题，但仍然是不够「优雅」的。 静态成员变量用以定义一些常量，静态成员函数用于定义一些和对象无关的功能尚可。

静态成员变量本质上是全局变量，静态成员函数本质上是全局函数。

普通成员和静态成员的区别： 1. 普通成员对象各个对象有各自的一份，静态成员变量只有一份，为该类的各个对象所共享。 2. `sizeof` 运算符不会计算静态成员变量。 3. 普通成员函数必须具体作用于某个对象，而静态成员函数并不具体作用于某个对象。 4. 静态成员通过类名就能访问，无须通过对象。

访问静态成员的方式： 1. 类名::成员名

```cpp
A::hello();
```

1. 对象名.成员名

   ```cpp
   A a;
   a.hello();
   ```

2. 指针-&gt;成员名

   ```cpp
   A *p = &a;
   p->hello();
   ```

3. 引用.成员名

   ```cpp
   A &ref = a;
   ref.hello();
   ref.world;
   ```

其他：

* 对静态成员变量，必须在定义类的文件中做一次初始化。否则编译能过，但连接不能通过。
* 在静态成员函数中，不能访问非静态成员变量和函数。

---

[\<Previous](ch-16-deconstructor.md) \| [Home](SUMMARY.md) \| [Next\>](ch-18-member-object-and-enclosed-class.md)